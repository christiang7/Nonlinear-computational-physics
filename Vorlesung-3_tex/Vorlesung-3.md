# Vorlesung-3
Created 2016-04-26


## Description

## Journal
 - [x] Backlog
    - [ ] 
 - [x] Doing

## Latex File

*Vorlesung-3.tex*
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

{\tmstrong{Vorlesung 3 26.04.2016}}

\

\href{/home/christian/Gedankenspeicher/Studium//Comp-NLD-1/Vorl3-A3-5.cpp}{Vorl3-A3-5.cpp}

\

\tmsession{shell}{default}{
  \tmoutput{Shell session inside TeXmacs pid = 13978}
  \tminput{Shell] }{g++ -o Vorl3-A3-5 Vorl3-A3-5.cpp \&\& ./Vorl3-A3-5 >
  V3-A3-5-E1.dat\\
  }
  \tminput{Shell] }{\ }
}

\

\tmsession{gnuplot}{default}{
  \tmoutput{This is a TeXmacs interface for GNUplot.}
  \tmunfoldedio{GNUplot] }{ plot 'V3-A3-5-E1.dat' using
  1:2}{\raisebox{0.0\height}{\includegraphics[width=10.411911321002231cm,height=7.288337924701561cm]{Vorlesung-3-1.pdf}}}
  \tminput{GNUplot] }{\ }
}

\end{document}

```

*make.sh*
```bash
noweb.py -RVorlesung-3.tex Vorlesung-3.md > Vorlesung-3.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-3.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-3.tex && date && xdg-open Vorlesung-3.pdf 2>/dev/null 
```


