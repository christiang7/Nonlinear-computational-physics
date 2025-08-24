# Vorlesung-7
Created 2016-05-31


## Description

## Journal
 - [x] Backlog
    - [ ] 
 - [x] Doing

## Latex File

*Vorlesung-7.tex*
```tex
\documentclass{article}
\usepackage[german]{babel}
\usepackage{hyperref,xcolor}

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

{\tmstrong{Vorlesung 7 31.05.2016}}

\

\href{/home/christian/Gedankenspeicher/Studium//Comp-NLD-1/Vorl6-A3-8.cpp}{Vorl6-A3-8.cpp}

\

\tmsession{shell}{default}{
  \tmoutput{Shell session inside TeXmacs pid = 13978}
  \tminput{Shell] }{g++ -o Vorl7-A3-10 Vorl7-A3-10.cpp \&\& ./Vorl7-A3-10 >
  V7-A3-10-E1.dat\\
  }
  \tminput{Shell] }{\ }
  \tminput{Shell] }{\ }
}

Plot gemitteltes R vs Epsilon

\tmsession{gnuplot}{default}{
  \tmoutput{This is a TeXmacs interface for GNUplot.}
  \tmunfoldedio{gnuplot] }{plot 'V7-A3-10-E1.dat' using
  2:1 with lines; \#beta0 = pi/4 , n =10, konz = 1, nsteps =
  5000}{"/home/christian/.TeXmacs/system/tmp/graph\_gnuplot\_109065/gnuplot.txt"
  line 8: warning: Cannot find or open file "V7-A3-10-E1.dat"
  
  "/home/christian/.TeXmacs/system/tmp/graph\_gnuplot\_109065/gnuplot.txt"
  line 8: No data in plot
  
  \ }
  \tminput{GNUplot] }{\ }
}

\

Animation mit Gnuplot aus C++ Programm heraus. Es wird sich ein Fenster
{\"o}ffnen, worin die Animation abgespielt wird. Zum Abbrechen der Animation
benutze Sitzung schlie{\ss}en

\tmsession{shell}{default}{
  \tmunfoldedio{Shell] }{g++ -o Vorl6-A3-9 Vorl6-A3-9.cpp \&\& ./Vorl6-A3-9
  \textbar  gnuplot}{{\scriptdead}}
  \tminput{Shell] }{\ }
}

\

\end{document}

```

*make.sh*
```bash
noweb.py -RVorlesung-7.tex Vorlesung-7.md > Vorlesung-7.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-7.tex && lualatex -interaction=nonstopmode -shell-escape Vorlesung-7.tex && date && xdg-open Vorlesung-7.pdf 2>/dev/null 
```


