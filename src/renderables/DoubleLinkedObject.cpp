/**
 * Doubly linked list of game objects.
 */

#include "DoubleLinkedObject.h"


/**
 * Constructor.
 */
DoubleLinkedObject::DoubleLinkedObject(Object* object) {
  this->object = object;
}

/**
 * Inserts the given doublelinked object after this object.
 * @param DoubleLinkedObject* to insert
 */
void DoubleLinkedObject::insertAfter(DoubleLinkedObject* object) {

  if(this->nextObject != nullptr){
    object->nextObject = this->nextObject;
    this->nextObject->lastObject = object;
  }

  this->nextObject = object;
  object->lastObject = this;
}

DoubleLinkedObject::

/**
 *
 * @param object
 */
void DoubleLinkedObject::insertBefore(DoubleLinkedObject* object){
  this->lastObject->insertAfter(object);
}

Object* DoubleLinkedObject::getObjectById(string id) {
  if(this->object->id == id){
    return this->object;
  } else if(this->nextObject == nullptr){
    return nullptr; // YA DONE MESSED UP
  } else {
    this->nextObject->getObjectById(id);
  }
}

/**
 *
 * @param n
 * @return
 */
Object* DoubleLinkedObject::getNthElement(int n) {
  return getNthElementRecurse(n, 0)->object;
}


/**
 * Recusive function.
 */
DoubleLinkedObject* DoubleLinkedObject::getNthElementRecurse(int n, int index) {
  if(index == n){
    return this;
  } else {
    return nextObject->getNthElementRecurse(n, index + 1);
  }
}



/**
 *
 */
void DoubleLinkedObject::remove() {
  this->lastObject->nextObject = this->nextObject;
  this->nextObject->lastObject = this->lastObject;
}

/**
 * Deletes all elements forward of this element.
 */
void DoubleLinkedObject::disposeOfList() {

  // Edge case - you messed up!
  if (this->nextObject == nullptr) {
    return;
  }

  if (this->nextObject->nextObject == nullptr) {
    delete (this->nextObject);
  } else {
    this->nextObject->disposeOfList();
    delete (this->nextObject);
  }

  this->nextObject = nullptr;
}