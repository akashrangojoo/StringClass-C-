#include "String.h"

const size_t String::npos=-1;

String& append ( const String& s ){
   int length=s.sz;
   expandMem(length);

   for(int i=sz,j=0;i<sz;i++) {
      p[i]=s.p[j];
      j++;
   }
   return *this;
}

String& append ( const String& s, const size_t& pos, const size_t& n ){
   String sub;
   sub.sz=n;
   int j=pos;
   for(int i=0;i<sub.sz;i++) {
      sub.p[i]=s.p[j];
      j++;
   }
   int length=sub.sz;
   expandMem(length);

   for(int i=sz,k=0;i<sz;i++) {
      p[i]=sub.p[k];
      k++;
   }
   return *this;
}

String& append ( const char* cs, const size_t& n ){
   int length=sz;
   expandMem(n);
   for(int i=length;i<sz;i++) {
      p[i]=cs[j];
      j++;
   }
}

String& append ( const char* cs ){
   int i=sz;
   while(cs[j]!=npos){
      expandMem(1);
      p[i]=cs[j];
   }
}

String& append ( const size_t& n, const char& c ){
   int length=sz;
   expandMem(n);
   for(int i=length;i<sz;i++) {
      p[i]=c;
   }
}

//INSERT FUNCTIONS START

String& insert ( const size_t& pos, const String& s ){
   int len1=s.sz;
   char* cs;
   expandMem(s.sz);
   for(int i=pos,j=0;i<sz;i++) {cs[j]=p[i];j++;}
   String sub;
   for(int i=pos,j=0;j<s.sz;i++){
      p[i]=s.p[j];
      j++;
   }
   int j=0;
   for(int i=pos+s.sz;i<sz;i++){
      p[i]=cs[j];
      j++;
   }
}

String& insert (const size_t& pos1,const String& s,const size_t& pos2,const size_t& n){
   int length=sz;
   char* cs;
   for(int i=pos1,j=0;i<sz;i++)  {cs[j]=p[i];j++;}
   String sub;
   sub.sz=n;
   for(int i=pos2,j=0;i<=n;i++,j++){
      sub.p[j]=s.p[i];
   }
   expandMem(n);
   for(int i=pos1,j=0;i<n;i++){
      p[i]=sub[j];
      j++;
   }
   for(int i=pos1+n,j=0;i<sz;i++,j++) {
      p[i]=cs[j];
   }
}

