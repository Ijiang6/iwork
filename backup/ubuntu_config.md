
Linux  Ubuntu 安装搜狗输入法


安装fcitx

sudo apt-get install fcitx  

fcitx安装失败则执行 sudo apt-get install -f 修复

  下载 搜狗安装包  命令行：sudo dpkg -i sogoupinyin_2.2.0.0108_amd64.deb 
    重启系统 选择搜狗输入法

linux 安装git

sudo apt-get install git 

<a>python 开发环境搭建</a>

安装 画图库 pip3 install matplotlib

# 方式 一

anaconda  安装 basemap

anaconda 下载:https://www.anaconda.com/download/#download

文件目录下:bash Anaconda3-4.2.0-Linux-x86_64.sh 安装 anaconda,用conda list 查看Python 库测试是否安装成功

ubuntu 下Anaconda3出现 conda：未找到命令


.bashrc文件中添加环境变量  export PATH="anaconda安装路径"/bin:$PATH, 终端执行 source ~/bashrc 使环境变量生效

安装Basemap :conda inatall basemap

ps:这样安装后 命令运行 python3(python) 运行环境是Anaconda 的bin 目录下 python3(python)命令

命令行 which +python3(python)查看运行命令位置

anaconda 安装basemap后如果用/usr/bin/python3(python)无法import basemap 

# 方式二

为/usr/bin/python3(python)配置basemap

命令行执行:sudo apt-get install python-matplotlib(python3-matplotlib) ->安装对应Python版本

命令行执行:sudo apt-get install python-mpltoolkits.basemap (python3-mpltoolkits.basemap)->安装对应Python版本

安装basemap前先提前安装好numpy, matplotlib, pyproj(百度看到有人这样说的)

踩坑:1-楼主用的python3 但装的是对应python 版本,导致安装成功,在python3中无法import 
    2-之前也这样装过basemap 但命令行 apt-get 下载速度太慢 多次尝试失败,后因ubuntu的一次更新开机无法进入图形桌面而无法解决,无奈重新装
    系统,装系统后更改了源,改为了阿里的,这次安装很顺利,不知道是否和源有关系

ubantu 换源

![2018-09-06%2023-11-31%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png](attachment:2018-09-06%2023-11-31%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![2018-09-06%2023-12-09%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png](attachment:2018-09-06%2023-12-09%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

# vim配置


一般配置:
    set nocompatible            " 关闭 vi 兼容模式
syntax on                   " 自动语法高亮
filetype plugin indent on   " 开启插件
set number                  " 显示行号
set nocursorline            " 不突出显示当前行
set shiftwidth=4            " 设定 << 和 >> 命令移动时的宽度为 4
set softtabstop=4           " 使得按退格键时可以一次删掉 4 个空格
set nobackup                " 覆盖文件时不备份
set nowb
set autochdir               " 自动切换当前目录为当前文件所在的目录
set backupcopy=yes          " 设置备份时的行为为覆盖
" set autoread                " set to auto read when a file changed from the outside
set ignorecase smartcase    " 搜索时忽略大小写，但在有一个或以上大写字母时仍大小写敏感
" set nowrapscan              " 禁止在搜索到文件两端时重新搜索
set incsearch               " 输入搜索内容时就显示搜索结果
set hlsearch                " 搜索时高亮显示被找到的文本
set noerrorbells            " 关闭错误信息响铃
set novisualbell            " 关闭使用可视响铃代替呼叫
set t_vb=                   " 置空错误铃声的终端代码
set showmatch               " 插入括号时，短暂地跳转到匹配的对应括号
set matchtime=2             " 短暂跳转到匹配括号的时间
" set nowrap                  " 不自动换行
set magic                  " 显示括号配对情况
set hidden                  " 允许在有未保存的修改时切换缓冲区，此时的修改由 vim 负责保存
set smartindent             " 开启新行时使用智能自动缩进
set backspace=indent,eol,start
                            " 不设定在插入状态无法用退格键和 Delete 键删除回车符
set cmdheight=1             " 设定命令行的行数为 1
set laststatus=1            " 显示状态栏 (默认值为 1, 无法显示状态栏)
" set foldenable              " 开始折叠
" set foldmethod=syntax       " 设置语法折叠
" set foldcolumn=0            " 设置折叠区域的宽度
" setlocal foldlevel=1        " 设置折叠层数为
" set foldclose=all           " 设置为自动关闭折叠
" colorscheme colorzone       " 设定配色方案
set autowrite
"set ruler                   " 打开状态栏标尺
"set cursorline              " 突出显示当前行

vim 主题下载：
https://vimcolors.com/
http://www.easycolor.cc/vim/list.html

插件管理器 vbundle安装 :git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim

安装说明文档(下载目录下readme.md或者https://github.com/muahao/Vundle.vim)配置.vimrc(vim配置文件)

NERDTree Git地址:https://github.com/scrooloose/nerdtree 可查看相关安装文档

安装NERDTree:根据bundle说明文档在相应位置添加:Plugin 'git://github.com/scrooloose/nerdtree.git'

运行vim 输入:BundleInatall  选择刚刚添加NERDTree git路径回车确认安装,完成后用:NERDTree 查看是否安装成功 

NERDTree 配置:
    

 let g:NERDTreeIndicatorMapCustom = {
    \ "Modified"  : "✹",
    \ "Staged"    : "✚",
    \ "Untracked" : "✭",
    \ "Renamed"   : "➜",
    \ "Unmerged"  : "═",
    \ "Deleted"   : "✖",
    \ "Dirty"     : "✗",
    \ "Clean"     : "✔︎",
    \ 'Ignored'   : '☒',
    \ "Unknown"   : "?"
    \ }//配合 NERDTree -git-plugin 插件显示git信息
   map <F2> :NERDTreeToggle<CR>//显示-隐藏
   autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") &&b:NERDTreeType == "primary") | q | endif//关闭时没有
打开其他文件的自动关闭
   autocmd vimenter * NERDTree//启动vim 时自动运行NERDTree

YCM安装与配置

bundle方式下载YCM
安装CMake
切换到bunlde目录下执行install.sh 或者 install.py


参考:
    https://github.com/Valloric/YouCompleteMe#ubuntu-linux-x64
        https://www.jianshu.com/p/d908ce81017a?nomobile=yes

./install.sh --clang-completer

复制 .ycm_extra_conf.py 文件:cp ~/.vim/bundle/YouCompleteMe/third_party/ycmd/examples/.ycm_extra_conf.py ~/.vim/

注意下面的 python 解释器的路径要和编译 ycm_core 的时候使用的 python 解释器是相同的版本（2 或 3）
et g:ycm_server_python_interpreter='/usr/bin/python3'//我用的python3
let g:ycm_global_ycm_extra_conf='~/.vim/.ycm_extra_conf.py'

# ubantu系统美化

精美壁纸下载：https://alpha.wallhaven.cc/
    

sudo apt install gnome-tweak-tool

添加扩展：sudo apt-get install gnome-shell-extensions

打开gone-tweak-tool 　打开ｕｓｅｒＴｈｅａｍ（没有此选项需重启）

插件管理：https://extensions.gnome.org/
    
sudo apt install chrome-gnome-shell 
资料参考：https://linux.cn/article-9447-1.html

主题资源下载：https://www.gnome-look.org/

主题　图标　更改教程：https://blog.csdn.net/zyqblog/article/details/80152016
