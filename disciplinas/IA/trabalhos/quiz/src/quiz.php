<!DOCTYPE html>
<html lang="pt-br">
<head>
	<meta charset="UTF-8"/>
	<meta name="description" content="Quiz - IA"/>
	<meta name="viewport" content="width=device-width, initial-scale=1"/>
	<link rel="stylesheet" href="radio.css">
	<title>Quiz - IA </title>
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js"></script>
	<script type="text/javascript">
		jQuery('#ajax_form').ready(function(){
			jQuery('#ajax_form').submit(function(){
				var dados = jQuery(this).serialize();
				var resposta;

				jQuery.ajax({
					type: "POST",
					url: "questao.php",
					data: dados,
					success: function( data )
					{
						// alert(typeof data);
						if($("#opcao1").is(":checked"))
							{resposta = $("#opcao1").attr("value");
						resposta = $("#opcao1").attr("value");
							// alert("resposta selecionada pelo usuario: " + $("#opcao1").attr("value"));
						}
						if($("#opcao2").is(":checked"))
						{
							resposta = $("#opcao2").attr("value");
							// alert("resposta selecionada pelo usuario: " + $("#opcao2").attr("value"));
						}
						if($("#opcao3").is(":checked"))
						{
							resposta = $("#opcao3").attr("value");
							// alert("resposta selecionada pelo usuario: " + $("#opcao3").attr("value"));
						}
						if(data != resposta)
						{
							alert("Não foi desta vez! Tente Denovo! A resposta correta é: " + data);
						}
						else
						{
							alert("Parabéns! Vamos para a próxima pergunta!");
						}
						/* Bug fixed no firefox by Marcelo Barbosa */
						$('form')[0].reset();
						location.reload();
					}
				});

				return false;
			});
		});
	</script>

</head>
<body>
	<?
	$numquestion = rand(1,3);
	$cmd = "nice -n15 /usr/bin/swipl -f questao.pl -g questao\(" . $numquestion . "\),halt -q";
	exec( $cmd, $output );
	$alternativa = str_replace('[','',$output[1]);
	$alternativa = str_replace(']','',$alternativa);
	$alternativa = explode(',', $alternativa);
	?>
	
	<h1><span class="label label-default" id="enunciado"><? echo $output[0] ?></span></h1>
	
	<form method="POST" action="" class="form-horizontal" id="ajax_form">
		<div>
			<input type="radio" class="radio" id="opcao1"  name="alternativa" value="<? echo $alternativa[0] ?>"/>
			<label for="opcao1"><? echo $alternativa[0] ?></label>
		</div>
		<div>
			<input type="radio" class="radio" id="opcao2"  name="alternativa" value="<? echo $alternativa[1] ?>"/>
			<label for="opcao2"><? echo $alternativa[1] ?></label>
		</div>
		<div>
			<input type="radio" class="radio" id="opcao3"  name="alternativa" value="<? echo $alternativa[2] ?>"/>
			<label for="opcao3"><? echo $alternativa[2] ?></label>
		</div>


		<input type="hidden" name="questao" value="<? echo $numquestion ?>">


		<div>
			<button class="button" type="">Confirmar</button>

		</form>

	</body>
	</html>