#!/bin/zsh

# Coloring of ls
unset LSCOLORS
export CLICOLOR=1
export CLICOLOR_FORCE=1

# Set up git-prompt
source ~/.git-prompt.sh
setopt PROMPT_SUBST; 
PS1='
%F{cyan}%T %F{green}%~ %B%F{red}$(__git_ps1 "(%s)")%b
%F{white}\$ '

# Set up git-completion
fpath=(~/.zsh $fpath)

autoload -U compinit; compinit

# alias
alias ~='cd ~'
alias ..='cd ..'
alias ....='cd ../..'
alias ......='cd ../../..'
alias ls='ls -TtrhgF' # T for timestamp, t sort by time modified, r for reverse order, h for human readable size, g for group, F for classify
alias rm='rm -i'
alias read='cat README*'
alias grep='grep -i --color=auto'
alias v='vim'
alias gv='mvim'
alias cl='clear'
alias diff='colordiff'
alias echo='echo -e'
alias st='speedtest-cli'
alias g++='g++ -ggdb -std=c++11'
alias gdb='sudo gdb'

alias gita='git add .'
alias gitb='git branch'
alias gitc='git commit -a -m'
alias gitd='git diff .'
alias gits='git status .'
alias gitl='git log'


clear

# The next line updates PATH for the Google Cloud SDK.
if [ -f '/Users/leo/Downloads/google-cloud-sdk/path.bash.inc' ]; then source '/Users/leo/Downloads/google-cloud-sdk/path.bash.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/Users/leo/Downloads/google-cloud-sdk/completion.bash.inc' ]; then source '/Users/leo/Downloads/google-cloud-sdk/completion.bash.inc'; fi

# Setting Android adb
export ANDROID_HOME=$HOME/Library/Android/sdk
export PATH=$PATH:$ANDROID_HOME/tools
export PATH=$PATH:$ANDROID_HOME/tools/bin
export PATH=$PATH:$ANDROID_HOME/platform-tools

# Setting Go
export GOROOT=/usr/local/opt/go/libexec
export GOPATH=/Users/leo/Coding/go
export PATH=$PATH:$GOROOT/bin:$GOPATH/bin

export GOPATH=$HOME/Coding/go

# Setting PATH for Python 2.7
# The orginal version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/2.7/bin:${PATH}"
export PATH

# Setting to use the Git from the Github
export PATH="/usr/local/git/bin:$PATH"


