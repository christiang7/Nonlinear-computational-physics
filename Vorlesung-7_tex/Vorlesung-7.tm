<TeXmacs|2.1.4>

<style|<tuple|generic|german|old-spacing|old-dots|old-lengths>>

<\body>
  s<strong|Vorlesung 7 07.06.2016>

  \;

  <hlink|Vorl6-A3-8.cpp|/home/christian/Gedankenspeicher/Studium//Comp-NLD-1/Vorl6-A3-8.cpp>

  \;

  <\session|shell|default>
    <\output>
      Shell session inside TeXmacs pid = 13978
    </output>

    <\input|Shell] >
      g++ -o Vorl7-A3-10 Vorl7-A3-10.cpp && ./Vorl7-A3-10 \<gtr\>
      V7-A3-10-E1.dat<next-line>
    </input>

    <\input|Shell] >
      \;
    </input>

    <\input|Shell] >
      \;
    </input>
  </session>

  Plot gemitteltes R vs Epsilon

  <\session|gnuplot|default>
    <\output>
      This is a TeXmacs interface for GNUplot.
    </output>

    <\unfolded-io>
      gnuplot]\ 
    <|unfolded-io>
      plot 'V7-A3-10-E1.dat' using 2:1 with lines;\ 
    <|unfolded-io>
      "/home/christian/.TeXmacs/system/tmp/graph_gnuplot_109065/gnuplot.txt"
      line 8: warning: Cannot find or open file "V7-A3-10-E1.dat"

      "/home/christian/.TeXmacs/system/tmp/graph_gnuplot_109065/gnuplot.txt"
      line 8: No data in plot

      \;
    </unfolded-io>

    <\input>
      GNUplot]\ 
    <|input>
      \;
    </input>
  </session>

  \;

  Animation mit Gnuplot aus C++ Programm heraus. Es wird sich ein Fenster
  öffnen, worin die Animation abgespielt wird. Zum Abbrechen der Animation
  benutze Sitzung schlieÿen

  <\session|shell|default>
    <\unfolded-io|Shell] >
      g++ -o Vorl6-A3-9 Vorl6-A3-9.cpp && ./Vorl6-A3-9 \| gnuplot
    <|unfolded-io>
      <script-dead>
    </unfolded-io>

    <\input|Shell] >
      \;
    </input>
  </session>

  \;
</body>

<initial|<\collection>
</collection>>