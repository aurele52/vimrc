
"autoreload when chhange in term
set autoread

"autosave when control v
set autowrite

"no backup file
set nobackup
set noswapfile

"accept utf8
set encoding=utf-8

"wrap option
noremap j gj
noremap k gk

syntax on
set	hidden
set updatetime=500
set term=xterm-256color
set backspace=eol,indent,start
set scrolloff=7
set showmode
set showcmd
set nu
set mouse=a
set noshowmatch
set wrap
set cursorline
set noerrorbells
set incsearch
set ignorecase
set smartcase
set hlsearch

"set tab to 4 space
set tabstop=4



set autoindent

set completeopt=longest,menuone
set wildmenu
set wildmode=longest:full,list:full



set rnu
set colorcolumn=80
set numberwidth=1
set title
set background=dark
set history=1000 
nnoremap <esc><esc><esc> :noh<return><esc>
inoremap fj <esc>
