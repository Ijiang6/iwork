CC:= g++
TARGET:= threadpool
#INCLUDE:= -I./
LIBS:= -lpthread
# C++语言编译参数  
CXXFLAGS:= -std=c++11 -g -Wall -D_REENTRANT
# C预处理参数
# CPPFLAGS:=
mutex_conn_tool.o:=mutex_conn_tool.cpp
thread_task.o:=thread_task.cpp
thread_pool.o:=thread_pool.cpp
file_task.o:=file_task.cpp
OBJECTS :=thread_pool.o mutex_conn_tool.o file_task.o thread_task.o main.o
  
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)
  
# $@表示所有目标集  
%.o:%.cpp   
	$(CC) -c $(CXXFLAGS)  $< -o $@
  
.PHONY : clean
clean:   
	-rm -f $(OBJECTS) $(TARGET)
