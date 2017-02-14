template class<T> 
class SafeArray {
 public:
   SafeArray<T> list(int firstInvalidIndex);
   SafeArray<T> list(int firstValidIndex, int firstInvalidIndex); 
   T& operator[](int ndx); void print();
   int length(); 
   // fill in the declarations as indicated below 
   // the copy constructor: 
   
   // the overloaded assignment operator: 
   
   // the destructor:

 private:
   int firstValid;
   int firstInvalid;
   T *A;
};

// Provide below the implementations of the three constructors, the 
// destructor, the overloaded assignment and [ ] operators, the print 
// method and the length method
