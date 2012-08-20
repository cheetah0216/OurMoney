let SessionLoad = 1
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <Plug>LookupFileCE 
imap <silent> <expr> <F5> (pumvisible() ? "\<Plug>LookupFileCE" : "")."\\<Plug>LookupFile"
inoremap <S-Tab> 
map! <S-Insert> <MiddleMouse>
noremap  h
noremap <NL> j
noremap  k
noremap  l
nmap s :cs find s =expand("<cword>")
nmap g :cs find g =expand("<cword>")
nmap c :cs find c =expand("<cword>")
nmap t :cs find t =expand("<cword>")
nmap e :cs find e =expand("<cword>")
nmap f :cs find f =expand("<cfile>")
nmap i :cs find i ^=expand("<cfile>")$
nmap d :cs find d =expand("<cword>")
map ,t :TMiniBufExplorer
nmap <silent> ,lk :LUTags
nmap <silent> ,lb :LUBufs
nmap <silent> ,lw :LUWalk
nmap <silent> ,hl <Plug>MarkSet
vmap <silent> ,hl <Plug>MarkSet
nmap <silent> ,hh <Plug>MarkClear
vmap <silent> ,hh <Plug>MarkClear
nmap <silent> ,hr <Plug>MarkRegex
vmap <silent> ,hr <Plug>MarkRegex 
nmap ,ih :IHS
nmap ,is :IHS:A
nmap ,ihn :IHN
map ,mbe <Plug>MiniBufExplorer
map ,mbc <Plug>CMiniBufExplorer
map ,mbu <Plug>UMiniBufExplorer
map ,mbt <Plug>TMiniBufExplorer
map ,mq <Plug>MBEMarkCurrent
map <silent> ,sw :call SaveWorkSpace()
map <silent> ,ee :e ~/.vimrc
map <silent> ,ss :source ~/.vimrc
nmap ,w :w!
nmap gx <Plug>NetrwBrowseX
map <silent> mm <Plug>Vm_toggle_sign 
nmap wm :WMToggle
nnoremap <silent> <F12> :A
nnoremap <silent> <F3> :Grep
nnoremap <silent> <F4> :Rgrep
nmap <silent> <F5> <Plug>LookupFile
noremap <C-Down> j
noremap <C-Up> k
noremap <C-Left> h
noremap <C-Right> l
map <C-F2> <Plug>Vm_toggle_sign
map <F2> <Plug>Vm_goto_next_sign
map <S-F2> <Plug>Vm_goto_prev_sign
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
map <S-Insert> <MiddleMouse>
imap 	 
imap  =CtrlXPP()
imap ,ih :IHS
imap ,is :IHS:A
imap ,ihn :IHN
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set balloonexpr=BalloonDeclaration()
set completeopt=longest,menu
set cscopeprg=/usr/bin/cscope
set cscopequickfix=s-,c-,d-,i-,t-,e-
set cscopetag
set cscopetagorder=1
set cscopeverbose
set noequalalways
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=cn
set history=1000
set nomodeline
set mouse=a
set path=.,/usr/include,,,/home/liufei/github/OurMoney/**
set printoptions=paper:a4
set ruler
set runtimepath=~/.vim,/var/lib/vim/addons,/usr/share/vim/vimfiles,/usr/share/vim/vim73,/usr/share/vim/vimfiles/after,/var/lib/vim/addons/after,~/.vim/after
set sessionoptions=blank,buffers,folds,help,options,tabpages,winsize,sesdir,resize
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set tags=tags
set termencoding=utf-8
set updatetime=300
set window=54
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
exe "cd " . escape(expand("<sfile>:p:h"), ' ')
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +12 main.c
badd +46 socket.c
args /home/liufei/github/OurMoney/main.c
set lines=55 columns=150
edit main.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
argglobal
inoremap <buffer> <silent> ­ =EchoFuncP()
inoremap <buffer> <silent> ½ =EchoFuncN()
inoremap <buffer> <silent> ( (=EchoFunc()
inoremap <buffer> <silent> ) =EchoFuncClear())
setlocal keymap=
setlocal noarabic
setlocal noautoindent
setlocal balloonexpr=
setlocal nobinary
setlocal bufhidden=
setlocal buflisted
setlocal buftype=
setlocal cindent
setlocal cinkeys=0{,0},0),:,0#,!^F,o,O,e
setlocal cinoptions=
setlocal cinwords=if,else,while,do,for,switch
setlocal colorcolumn=
setlocal comments=sO:*\ -,mO:*\ \ ,exO:*/,s1:/*,mb:*,ex:*/,://
setlocal commentstring=/*%s*/
setlocal complete=.,w,b,u,t,i
setlocal concealcursor=
setlocal conceallevel=0
setlocal completefunc=
setlocal nocopyindent
setlocal cryptmethod=
setlocal nocursorbind
setlocal nocursorcolumn
setlocal nocursorline
setlocal define=
setlocal dictionary=
setlocal nodiff
setlocal equalprg=
setlocal errorformat=
setlocal noexpandtab
if &filetype != 'c'
setlocal filetype=c
endif
setlocal foldcolumn=0
setlocal foldenable
setlocal foldexpr=0
setlocal foldignore=#
set foldlevel=100
setlocal foldlevel=0
setlocal foldmarker={{{,}}}
set foldmethod=syntax
setlocal foldmethod=manual
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldtext=foldtext()
setlocal formatexpr=
setlocal formatoptions=croql
setlocal formatlistpat=^\\s*\\d\\+[\\]:.)}\\t\ ]\\s*
setlocal grepprg=
setlocal iminsert=0
setlocal imsearch=2
setlocal include=
setlocal includeexpr=
setlocal indentexpr=
setlocal indentkeys=0{,0},:,0#,!^F,o,O,e
setlocal noinfercase
setlocal iskeyword=@,48-57,_,192-255
setlocal keywordprg=
setlocal nolinebreak
setlocal nolisp
setlocal nolist
setlocal makeprg=
setlocal matchpairs=(:),{:},[:]
setlocal nomodeline
setlocal modifiable
setlocal nrformats=octal,hex
set number
setlocal number
setlocal numberwidth=4
setlocal omnifunc=ccomplete#Complete
setlocal path=
setlocal nopreserveindent
setlocal nopreviewwindow
setlocal quoteescape=\\
setlocal noreadonly
setlocal norelativenumber
setlocal norightleft
setlocal rightleftcmd=search
setlocal noscrollbind
setlocal shiftwidth=8
setlocal noshortname
setlocal nosmartindent
setlocal softtabstop=0
setlocal nospell
setlocal spellcapcheck=[.?!]\\_[\\])'\"\	\ ]\\+
setlocal spellfile=
setlocal spelllang=en
setlocal statusline=
setlocal suffixesadd=
setlocal swapfile
setlocal synmaxcol=3000
if &syntax != 'c'
setlocal syntax=c
endif
setlocal tabstop=8
setlocal tags=
setlocal textwidth=0
setlocal thesaurus=
setlocal noundofile
setlocal nowinfixheight
setlocal nowinfixwidth
setlocal wrap
setlocal wrapmargin=0
silent! normal! zE
let s:l = 17 - ((16 * winheight(0) + 27) / 54)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
17
normal! 06l
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
