 set nocompatible              " be iMproved, required
   filetype off                  " required
syntax enable
 let g:solarized_termcolors=256
    set background=light
    colorscheme solarized
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
set autowrite
set ruler                   " 打开状态栏标尺
set cursorline              " 突出显示当前行
set autoindent		    "自动对齐
set cindent		    "自动缩进
 inoremap ( ()<ESC>i
inoremap [ []<ESC>i

inoremap { {}<ESC>i

"inoremap < <><ESC>i

inoremap ' ''<ESC>i

inoremap " ""<ESC>i
" set foldenable              " 开始折叠
" set foldmethod=syntax       " 设置语法折叠
" set foldcolumn=0            " 设置折叠区域的宽度
" setlocal foldlevel=1        " 设置折叠层数为
" set foldclose=all           " 设置为自动关闭折叠
" colorscheme colorzone       " 设定配色方案
   " set the runtime path to include Vundle and initialize
   set rtp+=~/.vim/bundle/Vundle.vim
   call vundle#begin()
   " alternatively, pass a path where Vundle should install plugins
   "call vundle#begin('~/some/path/here')

   " let Vundle manage Vundle, required
   Plugin 'VundleVim/Vundle.vim'

   " The following are examples of different formats supported.
   " Keep Plugin commands between vundle#begin/end.
   " plugin on GitHub repo
 "  Plugin 'tpope/vim-fugitive'
   " plugin from http://vim-scripts.org/vim/scripts.html
   " Plugin 'L9'
   " Git plugin not hosted on GitHub
  " Plugin 'git://git.wincent.com/command-t.git'
   " git repos on your local machine (i.e. when working on your own plugin)
  " Plugin 'file:///home/gmarik/path/to/plugin'
  " intall NERDTree 
  Plugin 'git://github.com/scrooloose/nerdtree.git'
  Plugin 'Xuyuanp/nerdtree-git-plugin'
  Plugin 'Valloric/YouCompleteMe'
   " The sparkup vim script is in a subdirectory of this repo called vim.
   " Pass the path to set the runtimepath properly.
  " Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
   " Install L9 and avoid a Naming conflict if you've already installed a
   " different version somewhere else.
   " Plugin 'ascenator/L9', {'name': 'newL9'}

   " All of your Plugins must be added before the following line
   call vundle#end()            " required
   filetype plugin indent on    " required
   " To ignore plugin indent changes, instead use:
   "NERDTree config
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
    \ }
   map <F2> :NERDTreeToggle<CR>
   autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType") &&b:NERDTreeType == "primary") | q | endif
   autocmd vimenter * NERDTree
   let g:ycm_server_python_interpreter='/usr/bin/python3'
let g:ycm_global_ycm_extra_conf='~/.vim/.ycm_extra_conf.py'
