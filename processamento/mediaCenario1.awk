#Script para extrair os dados brutos da saída do programa

BEGIN{

	estrutura[10];
	n[10];

	deltaComp;
	deltaReg;
	deltaTempo;
	
	avgComp[10];
	avgReg[10];
	avgTempo[10];

	total[10];
	
	for(i = 0; i < 10; i++){

		avgComp[i] = 0;
		avgReg[i] = 0;
		avgTempo[i] = 0;
		total[i] = 0;
	
	}

}

$1 ~ /^1$/ && $2 ~ /^1000$/{
	estrutura[0] = $1
	n[0] = $2
	total[0]++;
	deltaComp = $3 - avgComp[0];
	avgComp[0] += deltaComp / total[0];
	deltaReg = $4 - avgReg[0];
	avgReg[0] += deltaReg / total[0];
	deltaTempo = $5 - avgTempo[0];
	avgTempo[0] += deltaTempo / total[0];

}

$1 ~ /^1$/ && $2 ~ /^5000$/{
	estrutura[1] = $1
	n[1] = $2
	total[1]++;
	deltaComp = $3 - avgComp[1];
	avgComp[1] += deltaComp / total[1];
	deltaReg = $4 - avgReg[1];
	avgReg[1] += deltaReg / total[1];
	deltaTempo = $5 - avgTempo[1];
	avgTempo[1] += deltaTempo / total[1];
}

$1 ~ /^1$/ && $2 ~ /^10000$/{
	estrutura[2] = $1
	n[2] = $2
	total[2]++;
	deltaComp = $3 - avgComp[2];
	avgComp[2] += deltaComp / total[2];
	deltaReg = $4 - avgReg[2];
	avgReg[2] += deltaReg / total[2];
	deltaTempo = $5 - avgTempo[2];
	avgTempo[2] += deltaTempo / total[2];
}

$1 ~ /^1$/ && $2 ~ /^50000$/{
	estrutura[3] = $1
	n[3] = $2
	total[3]++;
	deltaComp = $3 - avgComp[3];
	avgComp[3] += deltaComp / total[3];
	deltaReg = $4 - avgReg[3];
	avgReg[3] += deltaReg / total[3];
	deltaTempo = $5  - avgTempo[3];
	avgTempo[3] += deltaTempo / total[3];
}

$1 ~ /^1$/ && $2 ~ /^100000$/{
	estrutura[4] = $1
	n[4] = $2
	total[4]++;
	deltaComp = $3 - avgComp[4];
	avgComp[4] += deltaComp / total[4];
	deltaReg = $4 - avgReg[4];
	avgReg[4] += deltaReg / total[4];
	deltaTempo = $5  - avgTempo[4];
	avgTempo[4] += deltaTempo / total[4];

}

$1 ~ /^0$/ && $2 ~ /^1000$/{
	estrutura[5] = $1
	n[5] = $2
	total[5]++;
	deltaComp = $3 - avgComp[5];
	avgComp[5] += deltaComp / total[5];
	deltaReg = $4 - avgReg[5];
	avgReg[5] += deltaReg / total[5];
	deltaTempo = $5 - avgTempo[5];
	avgTempo[5] += deltaTempo / total[5];

}

$1 ~ /^0$/ && $2 ~ /^5000$/{
	estrutura[6] = $1
	n[6] = $2
	total[6]++;
	deltaComp = $3 - avgComp[6];
	avgComp[6] += deltaComp / total[6];
	deltaReg = $4 - avgReg[6];
	avgReg[6] += deltaReg / total[6];
	deltaTempo = $5 - avgTempo[6];
	avgTempo[6] += deltaTempo / total[6];
}

$1 ~ /^0$/ && $2 ~ /^10000$/{
	estrutura[7] = $1
	n[7] = $2
	total[7]++;
	deltaComp = $3 - avgComp[7];
	avgComp[7] += deltaComp / total[7];
	deltaReg = $4 - avgReg[7];
	avgReg[7] += deltaReg / total[7];
	deltaTempo = $5 - avgTempo[7];
	avgTempo[7] += deltaTempo / total[7];
}

$1 ~ /^0$/ && $2 ~ /^50000$/{
	estrutura[8] = $1
	n[8] = $2
	total[8]++;
	deltaComp = $3 - avgComp[8];
	avgComp[8] += deltaComp / total[8];
	deltaReg = $4 - avgReg[8];
	avgReg[8] += deltaReg / total[8];
	deltaTempo = $5  - avgTempo[8];
	avgTempo[8] += deltaTempo / total[8];
}

$1 ~ /^0$/ && $2 ~ /^100000$/{
	estrutura[9] = $1
	n[9] = $2
	total[9]++;
	deltaComp = $3 - avgComp[9];
	avgComp[9] += deltaComp / total[9];
	deltaReg = $4 - avgReg[9];
	avgReg[9] += deltaReg / total[9];
	deltaTempo = $5  - avgTempo[9];
	avgTempo[9] += deltaTempo / total[9];

}


END{

	for(i = 0; i < 10; i++){

		printf("%d,%d,%.1f,%.1f,%.1f\n", estrutura[i], n[i], avgComp[i], avgReg[i], avgTempo[i]) >> "tratados.csv";
	}
}
