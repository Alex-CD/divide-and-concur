#include "DoubleLinkedObject.h"


/**
 * Constructor for the doublelinkedObject class.
 * @param object object to be stored in this doublelinked object.
 * Does *not* set lastObject and nextObject - this should be done from the calling function.
 */
DoubleLinkedObject::DoubleLinkedObject(Object* object) {
  this->object = object;

  this->nextObject = nullptr;
  this->lastObject = nullptr;
}

/**
 * Inserts the given object into the linked list, after this element.
 * Sets the relevant last and next object pointers.
 * @param object to insert.
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
 * Inserts the given object into the linked list, before this object.
 * Sets the relevenat last and next object pointers.
 * @param object to insert.
 */
void DoubleLinkedObject::insertBefore(Object* object){
  this->lastObject->insertAfter(object);
}

/**
 * Gets the object with the given ID.
 * @param id string to search for.
 * @return Object with ID. Nullptr if no object found.
 */
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
 * Adds an object to the end of the linked list.
 * @param object to insert
 * @return pointer to the inserted object.
 */
Object *DoubleLinkedObject::addObject(Object *object) {

  if(this->nextObject != nullptr){
    return this->nextObject->addObject(object);
  }
  else {
    this->insertAfter(object);
    return this->nextObject->object;
  }
}

/**
 * Gets the nth object in the list forward of the current element.
 * (this element is the 0th element)
 * @param n the index of the element to fetch.
 * @return the nth object.
 */
Object* DoubleLinkedObject::getNthElement(int n) {
  return getNthElementRecurse(n, 0)->object;
}


/**
 * Internal method, used to find the element with the nth element.
 * @param n Index of the element to fetch
 * @param index Index of the current element.
 * @return The element of the nth index. Returns null if less than n elements in the list.
 */
DoubleLinkedObject* DoubleLinkedObject::getNthElementRecurse(int n, int index) {
  if(index == n){
    return this;
  }
  else if (this->nextObject == nullptr) {
    return nullptr;
  }
  else {
      return nextObject->getNthElementRecurse(n, index + 1);
  }
}


/**
 * Removes references to the current object.
 * DOES NOT DELETE ELEMENTS, SO KEEP TRACK OF THIS ELEMENT
 * BEFORE YOU DELETE IT IF YOU DON'T WANT A MEMORY LEAK.
 */
void DoubleLinkedObject::remove() {
  this->lastObject->nextObject = this->nextObject;
  this->nextObject->lastObject = this->lastObject;

  this->nextObject = nullptr;
  this->lastObject = nullptr;

}

/**
 * Deletes all elements forward of this element.
 * (does not delete this object)
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