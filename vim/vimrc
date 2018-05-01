
" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2011 Apr 15
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc

" When started as "evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish
endif

" Use Vim settings, rather than Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set nocompatible

" allow backspacing over everything in insert mode
set backspace=indent,eol,start

set nobackup		" do not keep a backup file, use versions instead
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching
set tabstop=2
set shiftwidth=2


" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
map Q gq

" CTRL-U in insert mode deletes a lot.  Use CTRL-G u to first break undo,
" so that you can undo CTRL-U after inserting a line break.
inoremap <C-U> <C-G>u<C-U>

" In many terminal emulators the mouse works just fine, thus enable it.
"if has('mouse')
"  set mouse=a
"endif

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Only do this part when compiled with support for autocommands.
if has("autocmd")

  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd FileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  " Also don't do it when the mark is in the first line, that is the default
  " position when opening a file.
  autocmd BufReadPost *
    \ if line("'\"") > 1 && line("'\"") <= line("$") |
    \   exe "normal! g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on

endif " has("autocmd")

" Convenient command to see the difference between the current buffer and the
" file it was loaded from, thus the changes you made.
" Only define it when not defined already.
if !exists(":DiffOrig")
  command DiffOrig vert new | set bt=nofile | r ++edit # | 0d_ | diffthis
		  \ | wincmd p | diffthis
endif

call pathogen#infect()
nnoremap <F5> :exe 'NERDTreeToggle'<CR>

set t_Co=256
syntax enable
set background=dark
let g:solarized_termcolors=256  
let g:solarized_termtrans=1
let g:solarized_contrast="normal"
let g:solarized_visibility="normal"

colorschem  solarized  

call togglebg#map("<F3>")
let jshint2_read = 1
let jshint2_save = 1

set nocompatible              " be iMproved, required
" filetype off                  " required
filetype on

" set the runtime path to include Vundle and initialize
" set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
" Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
" Git plugin not hosted on GitHub
" Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
Plugin 'captbaritone/better-indent-support-for-php-with-html'
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

let g:go_version_warning = 0

"字符编码
""vim编码设置为utf-8,支持中文输入
set fileencodings=utf-8,gb2312,gb18030,gbk,ucs-bom,cp936,latin1
set encoding=utf-8
set langmenu=zh_CN.utf-8

"语法和缩进
""设定vim与vi不兼容
set nocompatible
"自动缩进，即为新行自动添加与当前行同等的缩进
set autoindent
""类似C语言程序的缩进
set cindent
set showmatch
"检索时忽略大小写
set ignorecase
set hlsearch
""显示行号
set nu
filetype plugin indent on

"tab相关设置
""开启时，在行首按TAB将加入shiftwidth个空格，否则加入tabstop个空格。
set smarttab
"是将输入的TAB自动展开成空格。开启后要输入TAB，需要Ctrl-V<TAB>
set expandtab
set tabstop=4
""设定 << 和 >> 命令移动时的宽度为 4
set shiftwidth=4

"颜色方案
set t_Co=256
""使用molokai 配色方案
colorscheme molokai
"为光标所在行加下划线,molokai配色下为高亮一行
set cursorline
""语法高亮
syntax on

"插件设置
""pathogen settings
"启用pathogen进行插件管理
execute pathogen#infect()

""tagbar settings
"ctrl+t to open tarbar
nmap <C-T> :TagbarToggle<CR>

let g:tagbar_width = 20
""auto run tagbar when use vim
"autocmd VimEnter * nested :call tagbar#autoopen(1)
""tagbar window postion
let g:tagbar_right = 1
"let g:tagbar_left = 1
"
""nerdtree settings
"ctrl+n to open nerdtree
nmap <C-N> :NERDTree<CR>
""nerdtree window position 'left' or 'right'
let NERDTreeWinPos = 'left'
"nerdtree window Size
let NERDTreeWinSize = 30
let NERDTreeShowFiles = 1

""airline setting
"开启airline
set laststatus=2
""不检测行尾空格,trailing-white-space
let g:airline#extensions#whitespace#enabled = 0
"使用tab打开文件
""let g:airline#extensions#tabline#enabled = 1
"let g:airline#extensions#tabline#left_sep = ' '
""let g:airline#extensions#tabline#left_alt_sep = '|'

"Code folding
""set foldmethod=syntax
"代码块折叠
autocmd FileType python set foldmethod=indent
""autocmd FileType xml set foldmethod=indent
"autocmd FileType dia set foldmethod=indent

""command Model map for go
"go 语言快捷键支持
""gd 快速打开:GoDef，GoDef支持代码内跳转到指定函数
"gr 快速执行:GoRun , 运行go程序
au FileType go cnoremap gd :GoDef<CR>
au FileType go cnoremap gr :GoRun<CR>

let g:go_fmt_command = "goimports"
