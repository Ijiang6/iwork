##C字符串API

###字符串操作
** 复制   **
```
char *strcpy( char *to, const char *from );`//可以正确处理两者字符串重叠

```

```
void *memcpy( void *to, const void *from, size_t count );//两者字符串出现重叠时不能处理
```

```
 void *memmove( void *to, const void *from, size_t count );//可以处理两者字符串重复
```
```
char *strncpy( char *to, const char *from, size_t count );//复制的最大字符串数为 count,如果被拷贝字符串的长度小于count ,则用‘\0’填补
```
**字符串**
```
char *strncat( char *str1, const char *str2, size_t count );//复制的最大字符串为count ,bi并在str1末尾增加结束符
```

```
char *strcat( char *str1, const char *str2 );
```
**字符串长度**
```
size_t strlen( char *str );//返回字符串长度，不包括结束符（'\0'）

sizeof(str);//sizeof是单目（一个参数）运算符，计算结束符长度
 strlen():是函数
```
**字符串比较**
```
int strcmp( const char *str1, const char *str2 );
str1<str2 : return <0
str1=str2: return =0
str1>str2: return <0
```
```
int strncmp( const char *str1, const char *str2, size_t count );//比较最大count字符串
```
```

int stricmp(const char *string1, const char *string2);  
比较字符串string1和string2大小，和strcmp不同, 比较的是它们的小写字母版本.返回值与strcmp相同. 

int strcmpi(const char *string1, const char *string2);  
等价于stricmp函数, 只是提供一个向后兼容的版本.
```
```
int strnicmp(const char *string1, const char *string2, size_t count); 
//比较字符串string1和string2大小，只比较前面count个字符. 与strncmp不同的是, 比较的是它们的小写字母版本.  返回值与strncmp相同.
```
**忽略大小写比较字符串**
```
  int   strcasecmp(const char *s1, const char *s2);//?
   int   strncasecmp(const char *s1, const char *s2);//?
```
```

int memicmp(const void *buf1, const void *buf2, size_t count); 

比较buf1和buf2前面count个字节. 与memcmp不同的是, 它不区分大小写.
```

**从开始查找指定 ++字符++ **
```
char *strchr( const char *str, int ch ); //查找字符第一次出现的位置，成功返回查字符开始的字符串指针，查找失败返回NULL
```
void *memchr( const void *buffer, int ch, size_t count );//返回结果同上

char names[] = "Alan Bob Chris X Dave";
   if( memchr(names,'X',strlen(names)) == NULL )
     printf( "Didn't find an X\n" );
   else
     printf( "Found an X\n" );

```

**从末尾开始查找指定  ++字符++ **
```
char *strrchr( const char *str, int ch );//从字符串末尾开始反向查找字符，成功返回查字符开始的字符串指针，查找失败返回NULL
```
**查找指定++ 字符串++ 位置（偏移量）
```
size_t strspn( const char *str1, const char *str2 );//查找指定字符出现在str1,不在str2的位置（偏移量）
```
```
size_t strcspn( const char *str1, const char *str2 );//查找指定字符串 第一次出现的位置的下标（相对于首地址的偏移量）
```
**查找指定 ++字符串++ **
```
char *strstr( const char *str1, const char *str2 ); //失败返回NULL
```
```
char *strpbrk( const char *str1, const char *str2 );//返回str2中任意字符在str1中第一次出现的位置的指针
```
```
 char *strtok( char *str1, const char *str2 );
 //查找str1中 str2位置，返回位置之前的字符串，每次调用该函数str1的值都会被修改，修改后的值为查找到的位置，可用str1==NULL，判断到达str1末尾
 
  char str[] = "now # is the time for all # good men to come to the # aid of their country";
   char delims[] = "#";
   char *result = NULL;
   result = strtok( str, delims );
   while( result != NULL ) {
       printf( "result is \"%s\"\n", result );
       result = strtok( NULL, delims );
   }
display:
result is "now "
   result is " is the time for all "
   result is " good men to come to the "
   result is " aid of their country"

```
**字符串颠倒**
```
char *strrev(char *string);  //将结束符前的字符串颠倒
	char *str4="ABC";
	int L=sizeof(char)*strlen(str4)+1;
	char *str6=(char*)malloc(L);
	strncpy(str6,str4,4);
	char *s=strrev(str4);//错误
    char *s=strrev(str6);//正确
```
**字符串大小写转换**
```
char *_strupr(char *string);  //string指针不能是 char *string ="abc" 常量指针
将string中所有小写字母替换成相应的大写字母, 其它字符保持不变.  返回调整后的字符串的指针. 

char *_strlwr(char *string);  //string指针不能是 char *string ="abc" 常量指针
将string中所有大写字母替换成相应的小写字母, 其它字符保持不变.  返回调整后的字符串的指针.
```
**字符转设置**
```
char *strset(char *string, int c);  
将string串的所有字符设置为字符c, 遇到NULL结束符停止. 函数返回内容调整后的string指针. 

char *strnset(char *string, int c, size_t count);  
将string串开始count个字符设置为字符c, 如果count值大于string串的长度, 将用string的长度替换count值. 函数返回内容调整后的string指针. 

 void *memset( void *buffer, int ch, size_t count );
 The function memset() copies ch into the first count characters of buffer, and returns buffer. memset() is useful for intializing a section of memory to some value. For example, this command: 

 memset( the_array, '\0', sizeof(the_array) );

```

**字符串与数字的转换**

```
转为float
#include <stdlib.h>
  double atof( const char *str );//将str中数字转为double
   x = atof( "42.0is_the_answer" );
//x=42.0
```
```
转为int
 int atoi( const char *str );

int i =atoi("520.1314");
//i=520
```

```
转为long
long atol( const char *str );
```
```
long strtol( const char *start, char **end, int base );

unsigned long strtoul( const char *start, char **end, int base );
//base设置进制

char *s="42.0is_the_answer";
long a= strtol( s, &str6,0);//a=42  *str6=".0is_the_answer"
long a= strtol( s, &str6,0);//a=42  *str6=".0is_the_answer"

```
**字符串判断**
```
判断是否为数字或字母，否：返回0
int isalnum( int ch );
int isdigit( int ch );
```

```
判断是否为字母 ，否：返回0
 #include <ctype.h>
  int isalpha( int ch );
```
  
```
 int isgraph( int ch ) 检查是否是图形字符，等效于 isalnum() | ispunct()
```
 
```
 int isprint( int ch );是否可打印
```

```
int iscntrl( int ch );
The iscntrl() function returns non-zero if its argument is a control character (between 0 and 0x1F or equal to 0x7F). Otherwise, zero is returned. 
```
```

int isxdigit( int ch );//是否为16进制字符
The function isxdigit() returns non-zero if its argument is a hexidecimal digit (i.e. A-F, a-f, or 0-9). Otherwise, zero is returned.
```

int islower( int ch );//是否为小写
int isupper( int ch );//是否为大写
 int toupper( int ch );//转成大写
  int tolower( int ch );//转成小写


