/********************************************
 *  * NAME        :  PROG8.CC " THE N QUEENS PROBLEM"
 *  * AUTHOR      :  AKASH Z1717009
 *  * SUBMISSION  :  10/29/2015
 *  * ******************************************/
#include "String.h"

const size_t String::npos=-1;

/*************************************************
 *  *  * FUNCTION  :  String ()
 *   *  * USAGE     :  Default Constructor
 *  ************************************************/

String::String(){
   sz=1;	
   p=new char[sz];	
   p[0]='\0';	
}


/*************************************************
 *  *  * FUNCTION  :  String (const String& s)
 *   *  * USAGE     :  Overloaded Custructor
 *    ************************************************/


String::String(const String& s){
   unsigned len=0;
   for(len=0;s.p[len]!='\0';len++);	
   p=new char[len+1];	
   sz=len+1;	
   for(unsigned i=0;i<sz;i++)
      p[i]=s.p[i];
}

/*************************************************
 *  * FUNCTION  :  String ( const String& s, const size_t& pos, const size_t& n )
 *   * USAGE     :  Overloaded Custructor
 *    *************************************************/

String::String(const String& s, const size_t& pos, const size_t& n){
   sz=n+1;		
   p=new char[sz];
   for(unsigned i=pos,j=0; i<pos+n;i++,j++){
      p[j]=s.p[i];	
   }
   p[sz-1]='\0';
}


/*************************************************
 *  *  * FUNCTION  :  String ( const char* cs, const size_t& n )
 *   *  * USAGE     :  Overloaded Custructor
 *    ************************************************/

String::String(const char* cs, const size_t& n){    
   unsigned len;	
   for(len=0;cs[len]!='\0';len++);
   sz=n+1;	
   p=new char[sz];	
   for(unsigned i=0;(i<n&&i<sz-1);i++)
      p[i]=cs[i];	
   p[sz-1]='\0';	
}

/*************************************************
 *  *  * FUNCTION  :  String (const char* s)
 *   *  * USAGE     :  Overloaded Custructor
 *    ************************************************/

String::String(const char* cs){
   unsigned len;	
   for(len=0;cs[len]!='\0';len++);
   sz=len+1;	
   p=new char[sz];
   for(unsigned i=0;i<sz-1;i++)
      p[i]=cs[i];
   p[sz-1]='\0';	
}


/*************************************************
 *  *  * FUNCTION  :   String ( const size_t& n , const char& c )
 *   *  * USAGE     :  Overloaded Custructor
 *    ************************************************/


String::String(const size_t& n, const char& c){
   sz=n+1;	
   p=new char[sz];	
   for(unsigned i=0;i<n;i++)
      p[i]=c;	
   p[n]='\0';	
}


/*************************************************
 *  *  * FUNCTION  :  ~String ()
 *  *  * USAGE     :  Default Destructor
 * ************************************************/

String::~String(){
   delete [] p;	
   sz=0;	
}			


/*************************************************
 *  *  * FUNCTION  :  operator= ( const String& s )
 *   *  * USAGE     :  Overload operator =
 *    ************************************************/

String& String::operator=(const String& s){
   sz=s.sz;
   delete [] p;	
   p=new char[sz];	
   for(unsigned i=0;i<sz-1;i++)
      p[i]=s.p[i];	
   p[sz-1]='\0';	
   return *this;	
}

/*************************************************
 *  *  * FUNCTION  :  operator= ( const char* cs )
 *   *  * USAGE     :  Overload operator =
 *    ************************************************/

String& String::operator=(const char* cs){
   unsigned len;
   for(len=0;cs[len]!='\0';len++);
   sz=len+1;		
   delete[] p;
   p=new char[sz];	
   for(unsigned i=0;i<(sz-1);i++)
      p[i]=cs[i];	
   p[sz-1]='\0';	
   return *this;	
}



/*************************************************
 *  *  * FUNCTION  :  operator= ( const char c )
 *   *  * USAGE     :  Overload operator =
 *    ************************************************/

String& String::operator=(const char& c){
   sz = 2;		
   delete[] p;	
   p = new char[sz];	
   p[0] = c;
   p[sz -1] = '\0';
   return *this;
}

/*************************************************
 *  *  * FUNCTION  :  operator+= ( const String& s )
 *      * USAGE     :  Overload operator +=
 *       * ***********************************************/


String& String :: operator+=(const String& s){
   int len=s.sz+sz-1;
   char *temp=new char[len];
   for(unsigned i=0;i<sz-1;i++)  temp[i]=p[i];
   for(unsigned j=0;j<s.length();j++)   temp[j+sz-1]=s.p[j];
   delete [] p;
   sz=len;
   p= new char[sz];
   for(unsigned k=0;k<sz;k++) p[k]=temp[k];
   return *this;
}


/*************************************************
 *  *  * FUNCTION  :  operator+= ( const char* cs )
 *   *  * USAGE     :  Overload operator +=
 *    ************************************************/
String& String :: operator+= (const char* cs){
   unsigned len;
   for(len=0;cs[len]!='\0';len++);
   char *temp=new char[sz+len];
   for(unsigned i=0;i<sz-1;i++) temp[i]=p[i];
   for(unsigned j=0;j<=len;j++) temp[sz-1+j]=cs[j];
   delete [] p;
   p= new char[sz+len];
   for(unsigned k=0;k<(sz+len);k++) p[k]=temp[k];
   sz=sz+len;
   return *this;
}


/*************************************************
 *  *   FUNCTION  :  operator+= ( const char& c )
 *   *   USAGE     :  Overload operator +=
 *    ************************************************/
String& String :: operator+= (const char& c){
   unsigned len=sz+1;
   char *temp=new char[len];
   for(unsigned i=0;i<sz-1;i++)    temp[i]=p[i];
   delete [] p;
   p= new char[len];
   sz=len;
   for(unsigned j=0;j<len-2;j++) p[j]=temp[j];
   p[len-2]=c;
   p[len-1]='\0';
   return *this;

}

/*************************************************
 *  *  *  *    FUNCTION  :  length ()
 *   *   *  *    USAGE     :  returns the length of the string
 *    *    *  * ************************************************/

size_t String::length() const{
   return sz-1;
}

/*************************************************
 *  *  *  *    FUNCTION  :  size()
 *   *   *  *    USAGE     :  returns tthe size of the string
 *    *    *  * ************************************************/

size_t String::size() const{
   return sz-1;
}

/*************************************************
 *  *  *  *    FUNCTION  :  empty( )
 *   *   *  *    USAGE     :  checks if the strnig is empty or not
 *    *    *  * ************************************************/

bool String::empty() const{
   return (sz==1);
}

/*************************************************
 *  *  *  *    FUNCTION  :  clear( )
 *   *   *  *    USAGE     :  clears and delets the string
 *    *    *  * ************************************************/

void String::clear(){
   delete [] p;
   sz=1;
   p=new char[1];
   p[0]='\0';
}

/*************************************************
 *  *  *    FUNCTION  :  operator<< ( ostream& os, const String& s )
 *   *  *    USAGE     :  overrides operator <<
 *    *  * ************************************************/

ostream& operator<< ( ostream& os, const String& s ){
   return os<<s.p;
}

/*************************************************
 *  *    FUNCTION  :  assign ( const String& s )
 *  *    USAGE     :  Assign the gien string
 *  * ************************************************/


String& String::assign(const String& s){
   return *this=s;
}

/*************************************************
 *  *  *    FUNCTION  :  assign ( const String& s )
 *   *  *    USAGE     :  Assign the gien string from given pos of size n
 *    *  * ************************************************/
String& String::assign(const String& s, const size_t& pos, const size_t& n){
   String s1(s,pos,n);
   delete[] p;
   sz=s1.sz;
   p=new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}


/*************************************************
 *  *  *    FUNCTION  :  assign ( const String& s )
 *   *  *    USAGE     :  Assign the gien char array of siz ein
 *    *  * ************************************************/
String& String::assign(const char*cs, const size_t& n){
   sz=n+1;
   p=new char[sz];
   for(unsigned i=0;i<sz-1;i++) p[i]=cs[i];
   p[sz-1]='\0';
   return *this;

}


/*************************************************
 *  *  *    FUNCTION  :  assign ( const String& s )
 *   *  *    USAGE     :  Assign the gien char array
 *    *  * ************************************************/


String& String::assign(const char*cs){
   String s1(cs);
   return *this=s1;
}


/*************************************************
 *  *  *    FUNCTION  :  assign ( const String& s )
 *   *  *    USAGE     :  Assign the gien char n times
 *    *  * ************************************************/


String& String::assign(const size_t& n,const char c){
   String strr(n,c);
   return *this=strr;  
}


/*************************************************
 *  *  *    FUNCTION  :  append (const String& s )
 *   *  *    USAGE     :  Append  the gien string in the end
 *    *  * ************************************************/

String& String::append(const String& s){
   String strr;
   return *this=(strr+=s);
}

/*************************************************
 *   *    FUNCTION  :  append (const String& s )
 *   *    USAGE     :  Append  the gien string in the end from pos of size n
 *   * ************************************************/

String& String::append(const String& s, const size_t& pos, const size_t& n){
   String strr(s,pos,n);
   return *this+=strr;
}

/*************************************************
 *  *   *    FUNCTION  :  append (const String& s )
 *   *   *    USAGE     :  Append  the gien char arrray in the end  of size n
 *    *   * ************************************************/

String& String::append(const char*cs, const size_t& n){
   String strr(cs,n);
   return *this+=strr;
}

/*************************************************
 *  *   *    FUNCTION  :  append (const String& s )
 *   *   *    USAGE     :  Append  the gien char array in the end 
 *    *   * ************************************************/

String& String::append(const char* cs){
   return *this+=cs;
}

/*************************************************
 *  *   *    FUNCTION  :  append (const String& s )
 *   *   *    USAGE     :  Append  the gien char in the end from pos of size n
 *    *   * ************************************************/

String& String::append(const size_t& n, const char& c){
   String s1(p);
   String s2(n,c);
   s1+=s2;
   delete[] p;
   sz=s1.sz;
   p= new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}

/*************************************************
 *  *   *    FUNCTION  : compare(const String& s)
 *   *   *    USAGE     :  Compare the given string with string
 *    *   * ************************************************/

int String::compare(const String& s)const{
   int v;
   bool gtFlag, ltFlag;
   bool eqFlag=gtFlag=ltFlag=true;
   if(sz!=s.sz) eqFlag=false;
   else for(unsigned i=0;i<s.length();i++){
      if(p[i]!=s.p[i]) eqFlag=false;
   }
   for(unsigned i=0,j=0;j<s.length();i++,j++){
      if(p[i]>=s.p[j]) ltFlag=false;
   }
   if(ltFlag||eqFlag) gtFlag=false;
   if(eqFlag) v=0;
   if(gtFlag) v=1;
   if(ltFlag) v=-1;   
   return v;
}

/*************************************************
 *    FUNCTION  :  compare(const char& cs)
 *    USAGE     :  Compare the given string with char array
 * ************************************************/

int String::compare(const char* cs)const{
   String s1(cs);
   return this->compare(s1);
}

/*************************************************
 *  *    FUNCTION  :  compare(const char& cs)
 *   *    USAGE     :  Compare the given string with string for given pos and size n
 *    * ************************************************/

int String::compare(const size_t& pos, const size_t& n, const String& s)const{
   String s1(p,pos,n);
   return s1.compare(s);
}

/*************************************************
 *  *    FUNCTION  :  compare(const char& cs)
 *   *    USAGE     :  Compare the given string with char array from pos and of size n
 *    * ************************************************/

int String::compare ( const size_t& pos, const size_t& n, const char* cs ) const{
   String s1(p,pos,n);
   String s2(cs);
   return s1.compare(s2);
}

/*************************************************
 *  *    FUNCTION  :  compare(const char& cs)
 *   *    USAGE     :  Compare the given string with String from pos1 in main string to pos 2 in passed string
 *                      of size n1 and n2
 *    * ************************************************/

int String::compare(const size_t& pos1, const size_t& n1, const String& s, const size_t& pos2, const size_t& n2 )const{
   String s1(p,pos1,n1);
   String s2(s,pos2,n2);
   return s1.compare(s2);
}

/*************************************************
 *  *    FUNCTION  :  compare(const char& cs)
 *   *    USAGE     :  Compare the given string with char array from pos to size n
 *    * ************************************************/

int String::compare ( const size_t& pos, const size_t& n1, const char* cs, const size_t& n2 )const{
   String s1(p,pos,n1);
   String s2(cs,0,n2);
   return s1.compare(s2);
}

/*************************************************
 *  *    FUNCTION  :  insert (const size_t& pos, const String& s)
 *   *    USAGE     :  Insert the given string at the gicen pos
 *    * ************************************************/

String& String::insert (const size_t& pos, const String& s){
   String s1(p);
   delete[] p;
   sz=s1.sz+s.sz-1;
   p=new char[sz];
   for(unsigned i=0;i<pos;i++) p[i]=s1.p[i];
   for(unsigned i=pos,j=0;j<s.sz-1;i++,j++) p[i]=s.p[j];
   for(unsigned i=pos+s.sz-1,j=pos;i<sz;j++,i++) p[i]=s1.p[j];
   return *this;
}

/*************************************************
 *  *  *    FUNCTION  :  insert (const size_t& pos, const String& s)
 *   *   *    USAGE     :  Insert the given string at the gicen pos1 from pos2
 *    *    * ************************************************/

String& String::insert ( const size_t& pos1, const String& s, const size_t& pos2, const size_t& n ){
   String s1(s,pos2,n);
   String s2(p);
   *this=s2.insert(pos1,s1);
   return *this;
}

/*************************************************
 *  *  *  *    FUNCTION  :  insert (const size_t& pos, const String& s)
 *   *   *   *    USAGE     :  Insert the given char array at the gicen pos1 from pos2
 *    *    *    * ************************************************/

String& String::insert ( const size_t& pos, const char* cs, const size_t& n ){
   String s1(cs,n);
   String s2(p);
   return *this=s2.insert(pos,s1);
}

/*************************************************
 *  *  *  *    FUNCTION  :  insert (const size_t& pos, const String& s)
 *   *   *   *    USAGE     :  Insert the given string at the gicen pos
 *    *    *    * ************************************************/

String& String::insert ( const size_t& pos, const char* cs ){
   String s1(cs);
   String s2(p);
   return *this=s2.insert(pos,s1);
}

/*************************************************
 *  *  *  *    FUNCTION  :  insert (const size_t& pos, const String& s)
 *   *   *   *    USAGE     :  Insert the given string at the gicen pos of size n
 *    *    *    * ************************************************/

String& String::insert ( const size_t& pos, const size_t& n, const char& c ){
   String s1(n,c);
   String s2(p);
   return *this=s2.insert(pos,s1);
}

/*************************************************
 *  *  *  *    FUNCTION  :  erase(const size_t& pos, const size_t& n)
 *   *   *   *    USAGE     :  Erase the string from pos to n chars
 *    *    *    * ************************************************/

String& String::erase(const size_t& pos, const size_t& n){
   String s1(p);
   delete [] p;
   sz=s1.sz-n;
   p=new char[sz];
   for(unsigned i=0;i<pos;i++) p[i]=s1.p[i];
   for(unsigned i=pos,j=pos+n;j<s1.sz;j++,i++) p[i]=s1.p[j];
   return *this;
}

/*************************************************
 *  *  *  *  *    FUNCTION  :  replace ( const size_t& pos, const size_t& n, const String& s )
 *   *   *   *   *    USAGE     : Replace the string wiht given string  from pos to n chars
 *    *    *    *    * ************************************************/

String& String::replace ( const size_t& pos, const size_t& n, const String& s ){
   String s1(p);
   s1.erase(pos,n);
   s1.insert(pos,s);
   sz=s1.sz;
   delete [] p;
   p=new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}

/*************************************************
 * *    FUNCTION  :  replace( const size_t& pos1, const size_t& n1, const String& s, const size_t& pos2, const size_t& n2 ){
 * *    USAGE     :  Replace the string wiht given string  from po2s to n chars from at po1
 * * ************************************************/

String& String::replace( const size_t& pos1, const size_t& n1, const String& s, const size_t& pos2, const size_t& n2 ){
   String s1(p);
   String s2(s,pos2,n2);
   s1.erase(pos1,n1);
   s1.insert(pos1,s2);
   sz=s1.sz;
   delete [] p;
   p= new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}

/*************************************************
 *   *    FUNCTION  : Replace ( const size_t& pos, const size_t& n1, const char* cs, const size_t& n2 )
 *   *    USAGE     :  Replace the string wiht given char array at pos1 from pos2 of size n
 *   * ************************************************/

String& String::replace ( const size_t& pos, const size_t& n1, const char* cs, const size_t& n2 ){
   String s1(p);
   String s2(cs,n2);
   s1.erase(pos,n1);
   s1.insert(pos,s2);
   sz=s1.sz;
   delete [] p;
   p= new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}

/*************************************************
 *  *    FUNCTION  :  replace( const size_t& pos, const size_t& n, const char* cs )
 *  *    USAGE     :  Replace the given char array from pos to size n
 *  * ************************************************/

String& String::replace( const size_t& pos, const size_t& n, const char* cs ){
   String s1(p);
   String s2(cs);
   s1.replace(pos,n,s2);
   sz=s1.sz;
   delete [] p;
   p= new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}
/*************************************************
 *   *  FUNCTION : replace ( const size_t& pos, const size_t& n1, const size_t& n2, const char& c )
 *   *  USAGE     :  Replace the given char array from pos to size n
 *   * ************************************************/


String& String::replace ( const size_t& pos, const size_t& n1, const size_t& n2, const char& c ){
   String s1(p);
   String s2(n2,c);
   s1.replace(pos,n1,s2);
   sz=s1.sz;
   delete [] p;
   p= new char[sz];
   for(unsigned i=0;i<sz;i++) p[i]=s1.p[i];
   return *this;
}

/*************************************************
 *  *  *    FUNCTION  :  copy(char* cs,const size_t& n,const size_t& pos)
 *   *  *    USAGE     :  copies one string to another
 *    *  * ************************************************/

size_t String::copy(char* cs,const size_t& n,const size_t& pos)const{
   size_t i,j;
   for(i=pos,j=0;j<n;j++,i++) cs[j]=p[i];
   return j;
}

/*************************************************
 *  *  *    FUNCTION  :  swap(String & s)
 *   *  *    USAGE     :  swaps the two string
 *    *  * ************************************************/

void String::swap(String & s){
   const size_t bufSize = sz; char buffer [bufSize];
   size_t len = this->copy (buffer,sz-1,0); buffer [ len ] = 0;
   *this=s;
   s=buffer;
}

