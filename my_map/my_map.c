#include "map_mtm.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct node {
    MapKeyElement key;
    MapDataElement data;
    struct node* next;
} * Node;

struct Map_t {
    int size;
    Node first;
    Node current;
    copyMapKeyElements copy_key;
    freeMapKeyElements free_key;
    copyMapDataElements copy_data;
    freeMapDataElements free_data;
    compareMapKeyElements compare_keys;
};
static void freeNode(Map map, Node node) {
    map->free_key(node->key);
    map->free_data(node->data);
    free(node->next);
    free(node);
}
static Node* mapGetNode(Map map, MapKeyElement key) {
    Node* current = &(map->first);
    while (*current != NULL && map->compare_keys((*current)->key, key) < 0) {
        current = &(*current)->next;
    }
    return current;
}
/*static Node mapCopyList(Map map, Node node) {
    Node new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) {
        return NULL;
    }
    if (node->next != NULL) {
        new_node->next = mapCopyList(map, node->next);
        if (new_node->next == NULL) {
            free(new_node);
            return NULL;
        }
    } else {
        new_node->next = NULL;
    }
    new_node->data = map->copy_data(node->data);
    new_node->key = map->copy_key(node->key);
    if (new_node->data == NULL || new_node->key == NULL) {
        freeNode(map, new_node);
        return NULL;
    }
    return new_node;
}*/
Map mapCreate(copyMapDataElements copyDataElement,
              copyMapKeyElements copyKeyElement,
              freeMapDataElements freeDataElement,
              freeMapKeyElements freeKeyElement,
              compareMapKeyElements compareKeyElements) {
    if (copyDataElement == NULL || copyKeyElement == NULL ||
        freeDataElement == NULL || freeKeyElement == NULL ||
        compareKeyElements == NULL) {
        return NULL;
    }
    Map map = malloc(sizeof(*map));
    if (map == NULL) {
        return NULL;
    }
    map->copy_key = copyKeyElement;
    map->free_key = freeDataElement;
    map->copy_data = copyDataElement;
    map->free_data = freeDataElement;
    map->compare_keys = compareKeyElements;
    map->size = 0;
    map->first = NULL;
    map->current = NULL;
    return map;
}
void mapDestroy(Map map) {
    if (map) {
        mapClear(map);
        free(map);
    }
}

Map mapCopy(Map map) {
    if (map == NULL) {
        return NULL;
    }
    Map new_map = mapCreate(map->copy_data, map->copy_key, map->free_data,
                            map->free_key, map->compare_keys);
    if (new_map == NULL) {
        return NULL;
    }
    Node current = map->first;
    while (current) {
        if (mapPut(new_map, current->key, current->data) != MAP_SUCCESS) {
            mapDestroy(new_map);
            return NULL;
        }
        current = current->next;
    }
    return new_map;
}
bool mapContains(Map map, MapKeyElement element) {
    if (map == NULL || element == NULL) {
        return false;
    }
    return mapGet(map, element) != NULL;
}
int mapGetSize(Map map) {
    if (map == NULL) {
        return -1;
    }
    return map->size;
}
MapResult mapPut(Map map,
                 MapKeyElement keyElement,
                 MapDataElement dataElement) {
    if (map == NULL || keyElement == NULL || dataElement == NULL) {
        return MAP_NULL_ARGUMENT;
    }
    Node* new_Element = mapGetNode(map, keyElement);
    if (*new_Element == NULL ||
        map->compare_keys((*new_Element)->key, keyElement) != 0) {
        Node new_node = malloc(sizeof(*new_node));
        if (new_node == NULL) {
            return MAP_OUT_OF_MEMORY;
        }
        new_node->key = map->copy_key(keyElement);
        new_node->data = map->copy_data(dataElement);
        new_node->next = NULL;
        if (new_node->key == NULL || new_node->data == NULL) {
            freeNode(map, new_node);
            return MAP_OUT_OF_MEMORY;
        }
        new_node->next = *new_Element;
        *new_Element = new_node;
        map->size++;
    } else {
        MapDataElement data = map->copy_data(dataElement);
        if (data == NULL) {
            return MAP_OUT_OF_MEMORY;
        }
        map->free_data((*new_Element)->data);
        (*new_Element)->data = data;
    }
    map->current = NULL;
    return MAP_SUCCESS;
}
MapDataElement mapGet(Map map, MapKeyElement keyElement) {
    if (map == NULL || keyElement == NULL) {
        return NULL;
    }
    Node* expected_place = mapGetNode(map, keyElement);
    return *expected_place != NULL &&
                   map->compare_keys((*expected_place)->key, keyElement) == 0
               ? (*expected_place)->data
               : NULL;
}
MapResult mapRemove(Map map, MapKeyElement keyElement) {
    if (map == NULL || keyElement == NULL) {
        return MAP_NULL_ARGUMENT;
    }
    Node* expected_place = mapGetNode(map, keyElement);
    Node expected_node = *expected_place;
    if (expected_node == NULL ||
        map->compare_keys(expected_node->key, keyElement) != 0) {
        return MAP_ITEM_DOES_NOT_EXIST;
    }
    map->size--;
    *expected_place = expected_node->next;
    expected_node->next = NULL;
    freeNode(map, expected_node);
    map->current = map->first;
    return MAP_SUCCESS;
}
MapKeyElement mapGetFirst(Map map) {
    if (map == NULL || map->first == NULL) {
        return NULL;
    }
    map->current = map->first;
    return map->current ? map->current->key : NULL;
}
MapKeyElement mapGetNext(Map map) {
    if (map == NULL || map->current == NULL) {
        return NULL;
    }
    map->current = map->current->next;
    return map->current ? map->current->key : NULL;
}
MapResult mapClear(Map map) {
    if (map == NULL) {
        return MAP_NULL_ARGUMENT;
    }
    while (map->first) {
        Node to_delete = map->first;
        map->first = map->first->next;
        map->free_key(to_delete->key);
        map->free_data(to_delete->data);
        free(to_delete);
    }
    map->size = 0;
    map->current = map->first;
    return MAP_SUCCESS;
}