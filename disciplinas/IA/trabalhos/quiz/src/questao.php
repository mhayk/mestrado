<?  
$questao = $_POST['questao'];
$resposta = $_POST['alternativa'];

$query = $questao . ',X';

$cmd = "nice -n15 /usr/bin/swipl -f questao.pl -g resposta\(" . $query . "\),halt -q;";

system( $cmd );

//echo $output;
// print_r($output);

?>
