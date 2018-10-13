
#git安装总结（ubuntu)

1、安装sudo apt-get install git
 查看 git版本： git --version

2、创建本地秘钥（用于后面ssh方式提交代码）
ssh-keygen -t rsa -C "your_email@youremail.com" 
三次回车：安装到默认目录
       不设置密码：（设置后每次提交都要输入密码）

3、登录github ，将公钥（.pub)添加到SSHKeys

4、git 设置本地用户名和邮箱
（github的用户名和邮箱）
git config --global user.name "your name"  
git config --global user.email test@runoob.com

5、初始化本地文件夹：
    方式一：cd 进入目录 ，执行git init
    方式二：git init 目录名

6、本地文件夹和github 库关联：
<1> github创建仓库hahaha之后,把github上的git下载到本地 git clone git@github.com:username/hahaha.git 
<2> github创建hahaha，把本地的库hahaha与github上的git关联 git remote add origin git@github.com:username/hahaha.git
<3> 把本地的东西都推上去 git push -u origin master/ 
 <4>   把上面的都下下来 git pull


7、代码提交：
<1>执行git add .，将本地的工程目录（包括子文件）都添加到本地的git仓库

<2>执行git commit -m "write some comment"，将本地的工程提交到本地的git仓库

<3>执行git remote add origin [github_repository_url]，将本地仓库与github上的仓库关联起来。
可以通过git remote -v查看github上的仓库地址。

<4>执行git pull origin master同步github仓库和本地仓库
<5>执行git push origin master将本地工程提交到github
