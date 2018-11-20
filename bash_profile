export CLICOLOR=1
export LSCOLORS=ExFxBxDxCxegedabagacad

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

source ~/.git-prompt.sh
PS1='\n\[\033[0;36m\]\t \[\033[0;32m\]\w\[\e[0;31m\]$(__git_ps1 " (%s)")\n\[\e[0m\]$ '

alias ~='cd ~'
alias ..='cd ..'
alias ....='cd ../..'
alias ......='cd ../../..'
alias test='cd ~/Coding/git/first_own_project'
alias ls='ls -thgFr' # t for time modified, h for size suffixes, g for group, F for filetype, r for reverse sorting by t
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

if [ -f ~/.git-completion.bash ]; then
  . ~/.git-completion.bash
fi


clear

# The next line updates PATH for the Google Cloud SDK.
if [ -f '/Users/leo/Downloads/google-cloud-sdk/path.bash.inc' ]; then source '/Users/leo/Downloads/google-cloud-sdk/path.bash.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/Users/leo/Downloads/google-cloud-sdk/completion.bash.inc' ]; then source '/Users/leo/Downloads/google-cloud-sdk/completion.bash.inc'; fi
