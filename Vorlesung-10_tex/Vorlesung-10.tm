<TeXmacs|1.99.4>

<style|<tuple|generic|german>>

<\body>
  <strong|Vorlesung 10 am 28.06.2016>

  Neuronennetzwerke. Zuerst ohne Kopplung

  <\session|shell|default>
    <\output>
      Shell session inside TeXmacs pid = 4659
    </output>

    <\input|Shell] >
      g++ -o Vorl10-A3-13 Vorl10-A3-13.cpp && ./Vorl10-A3-13 \<gtr\>
      V10-A3-13-E1.dat
    </input>

    <\input|Shell] >
      \;
    </input>
  </session>

  \;

  <\session|gnuplot|default>
    <\output>
      This is a TeXmacs interface for GNUplot.
    </output>

    <\unfolded-io>
      GNUplot]\ 
    <|unfolded-io>
      plot 'V10-A3-13-E1.dat' using 1:2\ 
    <|unfolded-io>
      <image|<tuple|<#>|ps>|0.7par|||>

      <\errput>
        \ \ \ \ \ \ \ \ \ line 0: warning: Skipping data file with no valid
        points

        \;

        gnuplot\<gtr\> plot 'V10-A3-13-E1.dat' using 1:2

        \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ ^

        \ \ \ \ \ \ \ \ \ line 0: x range is invalid

        \;
      </errput>
    </unfolded-io>

    <\input>
      GNUplot]\ 
    <|input>
      \;
    </input>
  </session>
</body>

<initial|<\collection>
</collection>>