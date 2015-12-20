"Project specific vim customisation
silent !ctags -R
set tag=./tags;

" Enable folding
set foldmethod=syntax
set nofoldenable

" Disable auto comment
set formatoptions-=cro

" Set makeprg to '[[ -f Makefile ]] && make || make -C ..'
set makeprg=[[\ -f\ Makefile\ ]]\ &&\ make\ \\\|\\\|\ make\ -C\ ..

" Ignore some files
set wildignore+=*/tmp/*,*.so,*.swp,*.zip,*.o
