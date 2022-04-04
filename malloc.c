void addNode (NODE **p, int n){
  NODE *t1,*t2;
  
  t1 = *p;
  t2 = t1 -> next;
  if (t1 -> val > n){
    aux -> next = *p;
      *p = &aux;
  }
  
  while ( t2-> val <= n) {
    t1 = t1 -> next;
    t2 = t2 -> next;
    
  }
 
  aux -> next = t -> next;
  t-> next = aux;
  
}
