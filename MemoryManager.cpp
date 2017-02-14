#include <cassert>
#include <iostream>
#include "dlUtils.h"
#include "MemoryManager.h"
#include "blockdata.h"

MemoryManager::MemoryManager(unsigned int memtotal): memsize(memtotal)
{
   baseptr = new unsigned char[memsize];
   blockdata originalBlock(memsize,true,baseptr);
   firstBlock = new dlNode<blockdata>(originalBlock,NULL,NULL);
}

void MemoryManager::showBlockList() 
{
  printDlList(firstBlock,"->");
}

void MemoryManager::splitBlock(dlNode<blockdata> *p, unsigned int chunksize)
{ // Put your code below

	int newSize = p->info.blocksize - chunksize;

	blockdata C(newSize, true, baseptr+chunksize);
	insertAfter(firstBlock, p, C );

	p->info.free = false;
	p->info.blocksize = chunksize;
		
	 

}

unsigned char * MemoryManager::malloc(unsigned int request)
{ // Put your code below
	
	dlNode<blockdata> *B = firstBlock;
	while (B!= NULL)
	{
		if (B->info.free == true && B->info.blocksize >= request)
		{
			splitBlock(B, request);
			return B->info.blockptr;
			break;
		}
		B=B->next;
	}
	
	return NULL;
}

void MemoryManager::mergeForward(dlNode<blockdata> *p)
{ // Put your code below
	int newSize = p->info.blocksize + p->next->info.blocksize;
	p->info.blocksize = newSize;
	
	dlNode<blockdata> *temp = p->next;
	if (temp->next == NULL)
		p->next = NULL;
	else
	{
		p->next = temp->next;
		p->next->prev = p;
		
	}

		delete temp;


}

void MemoryManager::mergeBackward(dlNode<blockdata> *p)
{ // Put your code below
	int newSize = p->prev->info.blocksize + p->info.blocksize;
	p->info.blocksize = newSize;
  p->info.blockptr = p->prev->info.blockptr;
	dlNode<blockdata> *temp = p->prev;
	if (temp->prev == NULL)
   {
		p->prev = NULL;
   firstBlock=p;
   }
	else
	{
		p->prev = temp->prev;
		p->prev->next = p;
	}
	delete temp;


	
}

void MemoryManager::free(unsigned char *ptr2block)
{ // Put your code below
	dlNode<blockdata> *curr=firstBlock;
	assert(curr != NULL);
	
	while (curr && curr->info.blockptr != ptr2block)
	{
		
		curr = curr->next;
	}
	assert(curr);
	


	if (curr->info.blockptr == ptr2block)
	{
		curr->info.free = true;

		if (curr->prev != NULL)
		{
			if (curr->prev->info.free == true && curr->info.free == true)
			{
				mergeBackward(curr);
			}
		}

		if (curr->next != NULL)
		{
			if (curr->info.free == true && curr->next->info.free == true)
			{
				mergeForward(curr);
			}

		};

	}
	else
		return;
			
		//}
	
	
}


