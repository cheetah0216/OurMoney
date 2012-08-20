if filereadable("./filenametags")
let g:LookupFile_TagExpr = '"./filenametags"'
endif
set path+=/home/liufei/github/OurMoney/**
if filereadable("session.vim")
source session.vim
endif
if filereadable("session.viminfo")
rviminfo session.viminfo
endif
