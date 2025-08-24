# Vorlesung-5
Created 2016-05-10


## Description

## Journal
 - [x] Backlog
    - [ ] 
 - [x] Doing

## Latex File

*Vorlesung-5.tex*
```tex
\documentclass{article}
\usepackage[german]{babel}
\usepackage{graphicx,hyperref,xcolor}

%%%%%%%%%% Start TeXmacs macros
\catcode`\>=\active \def>{
\fontencoding{T1}\selectfont\symbol{62}\fontencoding{\encodingdefault}}
\newcommand{\tminput}[2]{\trivlist{\item[\color{rgb:black,10;red,9;green,4;yellow,2}{#1}]{\color{blue!50!black}\mbox{}#2}}}
\newcommand{\tmoutput}[1]{#1}
\newcommand{\tmsession}[3]{{\tt#3}}
\newcommand{\tmstrong}[1]{\textbf{#1}}
\newcommand{\tmunfoldedio}[3]{\trivlist{\item[\color{rgb:black,10;red,9;green,4;yellow,2}{#1}]\mbox{}{\color{blue!50!black}#2}\item[]\mbox{}#3}}
%%%%%%%%%% End TeXmacs macros

\begin{document}

{\tmstrong{Vorlesung 5 10.05.2016}}

\

\href{/home/christian/Gedankenspeicher/Studium//Comp-NLD-1/Vorl3-A3-7.cpp}{Vorl4-A3-7.cpp}

\

\tmsession{shell}{default}{
  \tmoutput{Shell session inside TeXmacs pid = 13978}
  \tminput{Shell] }{g++ -o Vorl5-A3-7 Vorl5-A3-7.cpp \&\& ./Vorl5-A3-7 >
  V5-A3-7-E3.dat\\
  }
  \tminput{Shell] }{\ }
}

\

\tmsession{gnuplot}{default}{
  \tmoutput{This is a TeXmacs interface for GNUplot.}
  \tmunfoldedio{GNUplot] }{plot 'V5-A3-7-E1.dat' using 1:2 pt 7 ps 0.5; \#beta
  = pi/2 , n =10, konz = 1, nsteps =
  50000}{\raisebox{0.0\height}{\includegraphics[width=10.411911321002231cm,height=7.288337924701561cm]{Vorlesung-5-1.pdf}}}
  \tmunfoldedio{GNUplot] }{plot 'V5-A3-7-E2.dat' using 1:2 pt 7 ps 0.5; \#beta
  = pi/4, n =10, konz = 0.5, nsteps =
  50000}{\raisebox{0.0\height}{\includegraphics[width=10.411911321002231cm,height=7.288337924701561cm]{Vorlesung-5-2.pdf}}}
  \tmunfoldedio{GNUplot] }{plot 'V5-A3-7-E3.dat' using 1:2 pt 7 ps 0.5; \#beta
  = pi/1.5, n =10, konz = 0.01, nsteps =
  50000}{\raisebox{0.0\height}{\includegraphics[width=10.411911321002231cm,height=7.288337924701561cm]{Vorlesung-5-3.pdf}}}
  \tminput{GNUplot] }{\ }
}

\

Optimierung des Quellcodes auf Geschwindigkeit

\tmsession{shell}{default}{
  \tminput{Shell] }{g++ -o Vorl5-A3-7-opt Vorl5-A3-7-opt.cpp \&\&
  ./Vorl5-A3-7-opt > V5-A3-7-E3.dat}
  \tminput{Shell] }{\ }
}

\tmsession{gnuplot}{default}{
  \tmunfoldedio{GNUplot] }{plot 'V5-A3-7-E3.dat' using 1:2 pt 7 ps
  0.5}{\raisebox{0.0\height}{\includegraphics[width=10.411911321002231cm,height=7.288337924701561cm]{Vorlesung-5-4.pdf}}}
  \tminput{GNUplot] }{\ }
}

\end{document}

```

*make.sh*
```bash
noweb.py -RVorlesung-5.tex Vorlesung-5.md > Vorlesung-5.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-5.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-5.tex && date && xdg-open Vorlesung-5.pdf 2>/dev/null 
```


