//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Implementation file for the class ArrayBag.
 @file ArrayBag.cpp */

#include "ArrayBag.h"
#include <cstddef>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains


template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf


// NEW FUNCTIONS


template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagUnion(const ArrayBag<ItemType> &aBag)
{
	ArrayBag<ItemType> result;

	int numItems=0;
	numItems=getCurrentSize();
	for (int i=0; i<numItems; i++)
	{
		result.add(items[i]);
	}
	numItems=getCurrentSize();
	for (int i=0; i<numItems; i++)
	{
			result.add(aBag.items[i]);
	}
	return result;
}

//
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagIntersection(const ArrayBag<ItemType> &aBag)
{
 	ArrayBag<ItemType> result;

	int numEntries=getCurrentSize();
	int numEntries2=aBag.getCurrentSize();
	
 	for (int i=0; i<numEntries; i++)
 	{
		for (int j=0; j<numEntries2; j++)
		{
			if (items[i]==aBag.items[j])
			{
				result.add(items[i]);
			}
		}
		while(result.getFrequencyOf(items[i])>1)
		{
			result.remove(items[i]);
		}
	}
	return result;
}

//
template<class ItemType>
ArrayBag<ItemType> ArrayBag<ItemType>::bagDifference(const ArrayBag<ItemType> &aBag)
{
	ArrayBag<ItemType>result;
	
	int numItems=getCurrentSize();
	int numItems2=aBag.getCurrentSize();
	
	for (int i=0; i<numItems; i++)
	{
			result.add(items[i]);
	}

	for (int i=0; i<numItems2; i++)
	{
			result.add(aBag.items[i]);
	}
	
	for (int i=0; i<numItems; i++)
	{
		for (int j=0; j<numItems2; j++)
		{
			if (items[i]==aBag.items[j])
			{
				result.remove(items[i]);
				result.remove(aBag.items[j]);
			}
		}
		while(result.getFrequencyOf(items[i])>1)
		{
			result.remove(items[i]);
		}
	}
	return result;
}
