//
// Created by alex on 22/02/19.
//

#ifndef DAC_DOUBLELINKEDOBJECTS_H
#define DAC_DOUBLELINKEDOBJECTS_H

#include "Object.h"

/**
 * A doubly linked list of game objects.
 */
class DoubleLinkedObject {
 public:
  Object* object;
  explicit DoubleLinkedObject(Object* object);
  void remove();
  void insertAfter(Object *object);
  void insertBefore(Object *object);
  void disposeOfList();
  Object *addObject(Object *object);
  Object* getNthElement(int n);
  Object* getObjectById(string id);
  DoubleLinkedObject* nextObject;
  DoubleLinkedObject* lastObject;

 private:
  DoubleLinkedObject* getNthElementRecurse(int n, int index);
};

#endif //DAC_DOUBLELINKEDOBJECTS_H
