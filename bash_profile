export CLICOLOR=1
export LSCOLORS=ExFxBxDxCxegedabagacad

# Setting PATH for Python 2.7
# The orginal version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/2.7/bin:${PATH}"
export PATH

# Setting to use the Git from the Github
export PATH="/usr/local/git/bin:$PATH"

source ~/.git-prompt.sh
PS1='\n\[\033[0;36m\]\t \[\033[0;32m\]\w\[\e[0;31m\]$(__git_ps1 " (%s)")\n\[\e[0m\]$ '

alias ~='cd ~'
alias ..='cd ..'
alias ....='cd ..;cd ..'
alias ......='cd ..;cd ..; cd ..'
alias ls='ls -thgFr' # t for time modified, h for size suffixes, g for group, F for filetype, r for reverse sorting by t
alias rm='rm -i'
alias read='cat README*'
alias grep='grep -i --color=auto'
alias v='vim'
alias gv='mvim'
alias cl='clear'
alias diff='colordiff'
alias echo='echo -e'

alias gitb='git branch'
alias gits='git status'
alias gitl='git log'
alias gita='git add'
alias gitr='git rm'
alias gitc='git commit -a -m'
alias gitt='git tag'
alias gitm='git merge'
alias gitp='git push'
alias gitd='git diff'
clear

if [ -f ~/.git-completion.bash ]; then
  . ~/.git-completion.bash
fi
