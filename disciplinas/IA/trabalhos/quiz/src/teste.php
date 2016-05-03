<HTML>
<HEAD>
<TITLE>Chamada SWI-Prolog + PHP</TITLE>
</HEAD>

<H1>SWI-Prolog + PHP</H1>

<? 
  $cmd = "nice -n15 /usr/bin/swipl -f quiz.pl -g questao\(1,P,A,R\),halt";
?>

<P>
<PRE>
<? 
  system( $cmd );
  echo "\n";

  $output = exec( $cmd );
  //echo $output;
  echo "\n";

  exec( $cmd, $output );
  print_r( $output );
  echo "\n";

  $output = shell_exec( $cmd );
  echo $output;
  echo "\n";
?> 
</PRE>
</P>

</BODY>
</HTML>
