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
void DoubleLinkedObject::insertAfter(Object *object) {
  DoubleLinkedObject *oldNextObject = this->nextObject;
  this->nextObject = new DoubleLinkedObject(object);

  if(oldNextObject != nullptr){

    this->nextObject->lastObject = this;
    this->nextObject->nextObject = oldNextObject;
    oldNextObject->lastObject = this->nextObject;
  }
  else {
    this->nextObject->lastObject = this;
  }
}

/**
 *
 * @param object
 */
void DoubleLinkedObject::insertBefore(Object* object){
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

  return nullptr;
}

/**
 * Adds the given object to the end of the object queue.
 * @param object
 */
void DoubleLinkedObject::addObject(Object *object) {

  if(this->nextObject != nullptr){
    this->nextObject->addObject(object);
  }
  else {
    this->insertAfter(object);
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