" Configuration file for vim
set modelines=0		" CVE-2007-2438

" Normally we use vim-extensions. If you want true vi-compatibility
" remove change the following statements
set nocompatible	" Use Vim defaults instead of 100% vi compatibility
set backspace=2		" more powerful backspacing

" Don't write backup file if vim is being called by "crontab -e"
au BufWrite /private/tmp/crontab.* set nowritebackup nobackup
" Don't write backup file if vim is being called by "chpass"
au BufWrite /private/etc/pw.* set nowritebackup nobackup

"To turn off expandtab for editing makefiles"
autocmd FileType make setlocal noexpandtab

syntax on
colorscheme darkblue
set backspace=2
set backspace=indent,eol,start
set nu
set ai
set colorcolumn=80

set hlsearch



"mouse
set ttyfast
set mouse=a
set ttymouse=xterm2

set autoindent
set cindent
set laststatus=2
set statusline=
set statusline+=%1*\ %<%F
set statusline+=%8*\ %=\ row:%l/%L\ (%03p%%)
set statusline+=%9*\ col:%03c

"set tab to spaces
set expandtab
set tabstop=4
set sw=4



