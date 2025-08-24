# Vorlesung-10
Created 2016-06-28


## Description

## Journal
 - [x] Backlog
    - [ ] 
 - [x] Doing

## Latex File

*Vorlesung-10.tex*
```tex
\documentclass{article}
\usepackage[german]{babel}
\usepackage{xcolor}

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

{\tmstrong{Vorlesung 10 am 28.06.2016}}

Neuronennetzwerke. Zuerst ohne Kopplung

\tmsession{shell}{default}{
  \tmoutput{Shell session inside TeXmacs pid = 4659}
  \tminput{Shell] }{g++ -o Vorl10-A3-13 Vorl10-A3-13.cpp \&\& ./Vorl10-A3-13 >
  V10-A3-13-E1.dat}
  \tminput{Shell] }{\ }
}

\

\tmsession{gnuplot}{default}{
  \tmoutput{This is a TeXmacs interface for GNUplot.}
  \tmunfoldedio{gnuplot] }{plot 'V10-A3-13-E1.dat' using 1:2
  }{"/home/christian/.TeXmacs/system/tmp/graph\_gnuplot\_113689/gnuplot.txt"
  line 8: warning: Skipping data file with no valid points
  
  \
  
  plot 'V10-A3-13-E1.dat' using 1:2
  
  \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \^{}
  
  "/home/christian/.TeXmacs/system/tmp/graph\_gnuplot\_113689/gnuplot.txt"
  line 8: x range is invalid
  
  \ }
  \tminput{GNUplot] }{\ }
}

\end{document}

```

*make.sh*
```bash
noweb.py -RVorlesung-10.tex Vorlesung-10.md > Vorlesung-10.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-10.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-10.tex && date && xdg-open Vorlesung-10.pdf 2>/dev/null 
```


