template<class T>
T& Array<T>::operator[](int index) 
{
   if(index >= 0 && index < size)
      return A[index];
   else cerr << "Index out of range" << endl;         
}
