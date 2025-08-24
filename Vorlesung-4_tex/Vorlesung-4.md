===== Vorlesung-4 =====
# Vorlesung-4
Created 2025-08-24


## Description

## Journal
 - [x] Backlog
    - [ ] 
 - [x] Doing

## Latex File

*Vorlesung-4.tex*
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

{\tmstrong{Vorlesung 4 3.05.2016}}

\

\href{/home/christian/Gedankenspeicher/Studium//Comp-NLD-1/Vorl3-A3-5.cpp}{Vorl4-A3-6.cpp}

\

\tmsession{shell}{default}{
  \tmoutput{Shell session inside TeXmacs pid = 13978}
  \tminput{Shell] }{g++ -o Vorl4-A3-6 Vorl4-A3-6.cpp \&\& ./Vorl4-A3-6 >
  V4-A3-6-E1.dat\\
  }
  \tminput{Shell] }{\ }
}

\

\tmsession{gnuplot}{default}{
  \tmoutput{This is a TeXmacs interface for GNUplot.}
  \tmunfoldedio{GNUplot] }{ plot 'V4-A3-6-E1.dat' using 1:2 pt 7 ps
  0.5}{\raisebox{0.0\height}{\includegraphics[width=10.411911321002231cm,height=7.288337924701561cm]{Vorlesung-4-1.pdf}}}
  \tminput{GNUplot] }{\ }
}

\end{document}

```

*make.sh*
```bash
noweb.py -RVorlesung-4.tex Vorlesung-4.md > Vorlesung-4.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-4.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-4.tex && date && xdg-open Vorlesung-4.pdf 2>/dev/null 
```


