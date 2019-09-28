#Script para extrair os dados brutos da saída do programa
#Cenários de 2, 3 e 4

BEGIN{

	versao[25];
	n[25];

	deltaComp;
	deltaReg;
	deltaTempo;
	
	avgComp[25];
	avgReg[25];
	avgTempo[25];

	total[25];
	
	for(i = 0; i < 25; i++){

		avgComp[i] = 0;
		avgReg[i] = 0;
		avgTempo[i] = 0;
		total[i] = 0;
	
	}

}

$1 ~ /^0$/ && $2 ~ /^1000$/{
	versao[0] = $1
	n[0] = $2
	total[0]++;
	deltaComp = $3 - avgComp[0];
	avgComp[0] += deltaComp / total[0];
	deltaReg = $4 - avgReg[0];
	avgReg[0] += deltaReg / total[0];
	deltaTempo = $5 - avgTempo[0];
	avgTempo[0] += deltaTempo / total[0];

}

$1 ~ /^0$/ && $2 ~ /^5000$/{
	versao[1] = $1
	n[1] = $2
	total[1]++;
	deltaComp = $3 - avgComp[1];
	avgComp[1] += deltaComp / total[1];
	deltaReg = $4 - avgReg[1];
	avgReg[1] += deltaReg / total[1];
	deltaTempo = $5 - avgTempo[1];
	avgTempo[1] += deltaTempo / total[1];
}

$1 ~ /^0$/ && $2 ~ /^10000$/{
	versao[2] = $1
	n[2] = $2
	total[2]++;
	deltaComp = $3 - avgComp[2];
	avgComp[2] += deltaComp / total[2];
	deltaReg = $4 - avgReg[2];
	avgReg[2] += deltaReg / total[2];
	deltaTempo = $5 - avgTempo[2];
	avgTempo[2] += deltaTempo / total[2];
}

$1 ~ /^0$/ && $2 ~ /^50000$/{
	versao[3] = $1
	n[3] = $2
	total[3]++;
	deltaComp = $3 - avgComp[3];
	avgComp[3] += deltaComp / total[3];
	deltaReg = $4 - avgReg[3];
	avgReg[3] += deltaReg / total[3];
	deltaTempo = $5  - avgTempo[3];
	avgTempo[3] += deltaTempo / total[3];
}

$1 ~ /^0$/ && $2 ~ /^100000$/{
	versao[4] = $1
	n[4] = $2
	total[4]++;
	deltaComp = $3 - avgComp[4];
	avgComp[4] += deltaComp / total[4];
	deltaReg = $4 - avgReg[4];
	avgReg[4] += deltaReg / total[4];
	deltaTempo = $5  - avgTempo[4];
	avgTempo[4] += deltaTempo / total[4];

}

$1 ~ /^1$/ && $2 ~ /^1000$/{
	versao[5] = $1
	n[5] = $2
	total[5]++;
	deltaComp = $3 - avgComp[5];
	avgComp[5] += deltaComp / total[5];
	deltaReg = $4 - avgReg[5];
	avgReg[5] += deltaReg / total[5];
	deltaTempo = $5 - avgTempo[5];
	avgTempo[5] += deltaTempo / total[5];

}

$1 ~ /^1$/ && $2 ~ /^5000$/{
	versao[6] = $1
	n[6] = $2
	total[6]++;
	deltaComp = $3 - avgComp[6];
	avgComp[6] += deltaComp / total[6];
	deltaReg = $4 - avgReg[6];
	avgReg[6] += deltaReg / total[6];
	deltaTempo = $5 - avgTempo[6];
	avgTempo[6] += deltaTempo / total[6];
}

$1 ~ /^1$/ && $2 ~ /^10000$/{
	versao[7] = $1
	n[7] = $2
	total[7]++;
	deltaComp = $3 - avgComp[7];
	avgComp[7] += deltaComp / total[7];
	deltaReg = $4 - avgReg[7];
	avgReg[7] += deltaReg / total[7];
	deltaTempo = $5 - avgTempo[7];
	avgTempo[7] += deltaTempo / total[7];
}

$1 ~ /^1$/ && $2 ~ /^50000$/{
	versao[8] = $1
	n[8] = $2
	total[8]++;
	deltaComp = $3 - avgComp[8];
	avgComp[8] += deltaComp / total[8];
	deltaReg = $4 - avgReg[8];
	avgReg[8] += deltaReg / total[8];
	deltaTempo = $5  - avgTempo[8];
	avgTempo[8] += deltaTempo / total[8];
}

$1 ~ /^1$/ && $2 ~ /^100000$/{
	versao[9] = $1
	n[9] = $2
	total[9]++;
	deltaComp = $3 - avgComp[9];
	avgComp[9] += deltaComp / total[9];
	deltaReg = $4 - avgReg[9];
	avgReg[9] += deltaReg / total[9];
	deltaTempo = $5  - avgTempo[9];
	avgTempo[9] += deltaTempo / total[9];

}

$1 ~ /^2$/ && $2 ~ /^1000$/{
	versao[10] = $1
	n[10] = $2
	total[10]++;
	deltaComp = $3 - avgComp[10];
	avgComp[10] += deltaComp / total[10];
	deltaReg = $4 - avgReg[10];
	avgReg[10] += deltaReg / total[10];
	deltaTempo = $5 - avgTempo[10];
	avgTempo[10] += deltaTempo / total[10];

}

$1 ~ /^2$/ && $2 ~ /^5000$/{
	versao[11] = $1
	n[11] = $2
	total[11]++;
	deltaComp = $3 - avgComp[11];
	avgComp[11] += deltaComp / total[11];
	deltaReg = $4 - avgReg[11];
	avgReg[11] += deltaReg / total[11];
	deltaTempo = $5 - avgTempo[11];
	avgTempo[11] += deltaTempo / total[11];
}

$1 ~ /^2$/ && $2 ~ /^10000$/{
	versao[12] = $1
	n[12] = $2
	total[12]++;
	deltaComp = $3 - avgComp[12];
	avgComp[12] += deltaComp / total[12];
	deltaReg = $4 - avgReg[12];
	avgReg[12] += deltaReg / total[12];
	deltaTempo = $5 - avgTempo[12];
	avgTempo[12] += deltaTempo / total[12];
}

$1 ~ /^2$/ && $2 ~ /^50000$/{
	versao[13] = $1
	n[13] = $2
	total[13]++;
	deltaComp = $3 - avgComp[13];
	avgComp[13] += deltaComp / total[13];
	deltaReg = $4 - avgReg[13];
	avgReg[13] += deltaReg / total[13];
	deltaTempo = $5  - avgTempo[13];
	avgTempo[13] += deltaTempo / total[13];
}

$1 ~ /^2$/ && $2 ~ /^100000$/{
	versao[14] = $1
	n[14] = $2
	total[14]++;
	deltaComp = $3 - avgComp[14];
	avgComp[14] += deltaComp / total[14];
	deltaReg = $4 - avgReg[14];
	avgReg[14] += deltaReg / total[14];
	deltaTempo = $5  - avgTempo[14];
	avgTempo[14] += deltaTempo / total[14];

}

$1 ~ /^3$/ && $2 ~ /^1000$/{
	versao[15] = $1
	n[15] = $2
	total[15]++;
	deltaComp = $3 - avgComp[15];
	avgComp[15] += deltaComp / total[15];
	deltaReg = $4 - avgReg[15];
	avgReg[15] += deltaReg / total[15];
	deltaTempo = $5 - avgTempo[15];
	avgTempo[15] += deltaTempo / total[15];

}

$1 ~ /^3$/ && $2 ~ /^5000$/{
	versao[16] = $1
	n[16] = $2
	total[16]++;
	deltaComp = $3 - avgComp[16];
	avgComp[16] += deltaComp / total[16];
	deltaReg = $4 - avgReg[16];
	avgReg[16] += deltaReg / total[16];
	deltaTempo = $5 - avgTempo[16];
	avgTempo[16] += deltaTempo / total[16];
}

$1 ~ /^3$/ && $2 ~ /^10000$/{
	versao[17] = $1
	n[17] = $2
	total[17]++;
	deltaComp = $3 - avgComp[17];
	avgComp[17] += deltaComp / total[17];
	deltaReg = $4 - avgReg[17];
	avgReg[17] += deltaReg / total[17];
	deltaTempo = $5 - avgTempo[17];
	avgTempo[17] += deltaTempo / total[17];
}

$1 ~ /^3$/ && $2 ~ /^50000$/{
	versao[18] = $1
	n[18] = $2
	total[18]++;
	deltaComp = $3 - avgComp[18];
	avgComp[18] += deltaComp / total[18];
	deltaReg = $4 - avgReg[18];
	avgReg[18] += deltaReg / total[18];
	deltaTempo = $5  - avgTempo[18];
	avgTempo[18] += deltaTempo / total[18];
}

$1 ~ /^3$/ && $2 ~ /^100000$/{
	versao[19] = $1
	n[19] = $2
	total[19]++;
	deltaComp = $3 - avgComp[19];
	avgComp[19] += deltaComp / total[19];
	deltaReg = $4 - avgReg[19];
	avgReg[19] += deltaReg / total[19];
	deltaTempo = $5  - avgTempo[19];
	avgTempo[19] += deltaTempo / total[19];

}

$1 ~ /^4$/ && $2 ~ /^1000$/{
	versao[20] = $1
	n[20] = $2
	total[20]++;
	deltaComp = $3 - avgComp[20];
	avgComp[20] += deltaComp / total[20];
	deltaReg = $4 - avgReg[20];
	avgReg[20] += deltaReg / total[20];
	deltaTempo = $5 - avgTempo[20];
	avgTempo[20] += deltaTempo / total[20];

}

$1 ~ /^4$/ && $2 ~ /^5000$/{
	versao[21] = $1
	n[21] = $2
	total[21]++;
	deltaComp = $3 - avgComp[21];
	avgComp[21] += deltaComp / total[21];
	deltaReg = $4 - avgReg[21];
	avgReg[21] += deltaReg / total[21];
	deltaTempo = $5 - avgTempo[21];
	avgTempo[21] += deltaTempo / total[21];
}

$1 ~ /^4$/ && $2 ~ /^10000$/{
	versao[22] = $1
	n[22] = $2
	total[22]++;
	deltaComp = $3 - avgComp[22];
	avgComp[22] += deltaComp / total[22];
	deltaReg = $4 - avgReg[22];
	avgReg[22] += deltaReg / total[22];
	deltaTempo = $5 - avgTempo[22];
	avgTempo[22] += deltaTempo / total[22];
}

$1 ~ /^4$/ && $2 ~ /^50000$/{
	versao[23] = $1
	n[23] = $2
	total[23]++;
	deltaComp = $3 - avgComp[23];
	avgComp[23] += deltaComp / total[23];
	deltaReg = $4 - avgReg[23];
	avgReg[23] += deltaReg / total[23];
	deltaTempo = $5  - avgTempo[23];
	avgTempo[23] += deltaTempo / total[23];
}

$1 ~ /^4$/ && $2 ~ /^100000$/{
	versao[24] = $1
	n[24] = $2
	total[24]++;
	deltaComp = $3 - avgComp[24];
	avgComp[24] += deltaComp / total[24];
	deltaReg = $4 - avgReg[24];
	avgReg[24] += deltaReg / total[24];
	deltaTempo = $5  - avgTempo[24];
	avgTempo[24] += deltaTempo / total[24];

}

END{

	for(i = 0; i < 25; i++){

		printf("%d,%d,%.1f,%.1f,%.1f\n", versao[i], n[i], avgComp[i], avgReg[i], avgTempo[i]) >> "tratadosCenario2.csv";
	}
}
