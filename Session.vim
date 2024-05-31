let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/repos/DSA/Striver
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
if &shortmess =~ 'A'
  set shortmess=aoOA
else
  set shortmess=aoO
endif
badd +1 ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/output.txt
badd +2 ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/input.txt
badd +25 ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/sort_ll.cpp
badd +0 atozdsa/step6/med_probs_of_ll/sort_ll_of_012.cpp
argglobal
%argdel
$argadd ./
edit atozdsa/step6/med_probs_of_ll/sort_ll_of_012.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 111 + 85) / 170)
exe '2resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 2resize ' . ((&columns * 58 + 85) / 170)
exe '3resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 3resize ' . ((&columns * 58 + 85) / 170)
argglobal
balt ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/sort_ll.cpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 36 - ((33 * winheight(0) + 18) / 37)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 36
normal! 0
wincmd w
argglobal
if bufexists(fnamemodify("~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/input.txt", ":p")) | buffer ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/input.txt | else | edit ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/input.txt | endif
if &buftype ==# 'terminal'
  silent file ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/input.txt
endif
balt ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/sort_ll.cpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 2 - ((1 * winheight(0) + 9) / 18)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 07|
wincmd w
argglobal
if bufexists(fnamemodify("~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/output.txt", ":p")) | buffer ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/output.txt | else | edit ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/output.txt | endif
if &buftype ==# 'terminal'
  silent file ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/output.txt
endif
balt ~/repos/DSA/Striver/atozdsa/step6/med_probs_of_ll/sort_ll.cpp
setlocal fdm=expr
setlocal fde=nvim_treesitter#foldexpr()
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
let s:l = 1 - ((0 * winheight(0) + 9) / 18)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 111 + 85) / 170)
exe '2resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 2resize ' . ((&columns * 58 + 85) / 170)
exe '3resize ' . ((&lines * 18 + 20) / 40)
exe 'vert 3resize ' . ((&columns * 58 + 85) / 170)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
