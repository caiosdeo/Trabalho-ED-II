#Script para extrair os dados brutos da saída do programa

BEGIN{

	estrutura[36];
	estado[36];
	n[36];

	deltaComp;
	deltaReg;
	deltaTempo;
	
	avgComp[36];
	avgReg[36];
	avgTempo[36];

	total[36];
	
	for(i = 0; i < 36; i++){

		avgComp[i] = 0;
		avgReg[i] = 0;
		avgTempo[i] = 0;
		total[i] = 0;
	
	}

}

# $1         $2     $3  $4    $5   $6
# estrutura, estado, n, comp, reg, tempo
# 18 para insercao
# 18 para busca

# 0 - Arvore RubroNegra;
$1 ~ /^0$/ && $3 ~ /^1000$/{

	indice = 0;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^0$/ && $3 ~ /^5000$/{

	indice = 1;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^0$/ && $3 ~ /^10000$/{

	indice = 2;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^0$/ && $3 ~ /^50000$/{

	indice = 3;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^0$/ && $3 ~ /^100000$/{

	indice = 4;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^0$/ && $3 ~ /^500000$/{

	indice = 5;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

# 1 - Arvore B d = 2;
$1 ~ /^1$/ && $3 ~ /^1000$/{

	indice = 6;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^1$/ && $3 ~ /^5000$/{

	indice = 7;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^1$/ && $3 ~ /^10000$/{

	indice = 8;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^1$/ && $3 ~ /^50000$/{

	indice = 9;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^1$/ && $3 ~ /^100000$/{

	indice = 10;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^1$/ && $3 ~ /^500000$/{

	indice = 11;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

# 2 - Arvore B d = 20;
$1 ~ /^2$/ && $3 ~ /^1000$/{

	indice = 12;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^2$/ && $3 ~ /^5000$/{

	indice = 13;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^2$/ && $3 ~ /^10000$/{

	indice = 14;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^2$/ && $3 ~ /^50000$/{

	indice = 15;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^2$/ && $3 ~ /^100000$/{

	indice = 16;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

$1 ~ /^2$/ && $3 ~ /^500000$/{

	indice = 17;

	if($2 == 0){

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}
	else{

		indice = indice + 18;

		estrutura[indice] = $1
		estado[indice] = $2
		n[indice] = $3
		total[indice]++;
		deltaComp = $4 - avgComp[indice];
		avgComp[indice] += deltaComp / total[indice];
		deltaReg = $5 - avgReg[indice];
		avgReg[indice] += deltaReg / total[indice];
		deltaTempo = $6 - avgTempo[indice];
		avgTempo[indice] += deltaTempo / total[indice];

	}

}

END{

	for(i = 0; i < 36; i++){

		printf("%d,%d,%d,%.1f,%.1f,%.1f\n", estrutura[i], estado[i], n[i], avgComp[i], avgReg[i], avgTempo[i]) >> "mediasFase3.csv";
	}
}
