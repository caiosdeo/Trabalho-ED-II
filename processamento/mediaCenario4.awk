#Script para extrair os dados brutos da saída do programa

BEGIN{

	versao[30];
	n[30];

	deltaColi;
	
	avgColi[30];

	total[30];
	
	for(i = 0; i < 30; i++){

		avgColi[i] = 0;
		total[i] = 0;
	
	}

}

$1 ~ /^0$/ && $2 ~ /^1000$/{
	versao[0] = $1
	n[0] = $2
	total[0]++;
	deltaColi = $3 - avgColi[0];
	avgColi[0] += deltaColi / total[0];

}

$1 ~ /^0$/ && $2 ~ /^5000$/{
	versao[1] = $1
	n[1] = $2
	total[1]++;
	deltaColi = $3 - avgColi[1];
	avgColi[1] += deltaColi / total[1];
}

$1 ~ /^0$/ && $2 ~ /^10000$/{
	versao[2] = $1
	n[2] = $2
	total[2]++;
	deltaColi = $3 - avgColi[2];
	avgColi[2] += deltaColi / total[2];
}

$1 ~ /^0$/ && $2 ~ /^50000$/{
	versao[3] = $1
	n[3] = $2
	total[3]++;
	deltaColi = $3  - avgColi[3];
	avgColi[3] += deltaColi / total[3];
}

$1 ~ /^0$/ && $2 ~ /^100000$/{
	versao[4] = $1
	n[4] = $2
	total[4]++;
	deltaColi = $3  - avgColi[4];
	avgColi[4] += deltaColi / total[4];

}

$1 ~ /^0$/ && $2 ~ /^500000$/{
	versao[5] = $1
	n[5] = $2
	total[5]++;
	deltaColi = $3  - avgColi[5];
	avgColi[5] += deltaColi / total[5];

}

$1 ~ /^1$/ && $2 ~ /^1000$/{
	versao[6] = $1
	n[6] = $2
	total[6]++;
	deltaColi = $3 - avgColi[6];
	avgColi[6] += deltaColi / total[6];

}

$1 ~ /^1$/ && $2 ~ /^5000$/{
	versao[7] = $1
	n[7] = $2
	total[7]++;
	deltaColi = $3 - avgColi[7];
	avgColi[7] += deltaColi / total[7];
}

$1 ~ /^1$/ && $2 ~ /^10000$/{
	versao[8] = $1
	n[8] = $2
	total[8]++;
	deltaColi = $3 - avgColi[8];
	avgColi[8] += deltaColi / total[8];
}

$1 ~ /^1$/ && $2 ~ /^50000$/{
	versao[9] = $1
	n[9] = $2
	total[9]++;
	deltaColi = $3  - avgColi[9];
	avgColi[9] += deltaColi / total[9];
}

$1 ~ /^1$/ && $2 ~ /^100000$/{
	versao[10] = $1
	n[10] = $2
	total[10]++;
	deltaColi = $3  - avgColi[10];
	avgColi[10] += deltaColi / total[10];

}

$1 ~ /^1$/ && $2 ~ /^500000$/{
	versao[11] = $1
	n[11] = $2
	total[11]++;
	deltaColi = $3  - avgColi[11];
	avgColi[11] += deltaColi / total[11];

}

$1 ~ /^2$/ && $2 ~ /^1000$/{
	versao[12] = $1
	n[12] = $2
	total[12]++;
	deltaColi = $3 - avgColi[12];
	avgColi[12] += deltaColi / total[12];

}

$1 ~ /^2$/ && $2 ~ /^5000$/{
	versao[13] = $1
	n[13] = $2
	total[13]++;
	deltaColi = $3 - avgColi[13];
	avgColi[13] += deltaColi / total[13];
}

$1 ~ /^2$/ && $2 ~ /^10000$/{
	versao[14] = $1
	n[14] = $2
	total[14]++;
	deltaColi = $3 - avgColi[14];
	avgColi[14] += deltaColi / total[14];
}

$1 ~ /^2$/ && $2 ~ /^50000$/{
	versao[15] = $1
	n[15] = $2
	total[15]++;
	deltaColi = $3  - avgColi[15];
	avgColi[15] += deltaColi / total[15];
}

$1 ~ /^2$/ && $2 ~ /^100000$/{
	versao[16] = $1
	n[16] = $2
	total[16]++;
	deltaColi = $3  - avgColi[16];
	avgColi[16] += deltaColi / total[16];

}

$1 ~ /^2$/ && $2 ~ /^500000$/{
	versao[17] = $1
	n[17] = $2
	total[17]++;
	deltaColi = $3  - avgColi[17];
	avgColi[17] += deltaColi / total[17];

}

$1 ~ /^3$/ && $2 ~ /^1000$/{
	versao[18] = $1
	n[18] = $2
	total[18]++;
	deltaColi = $3 - avgColi[18];
	avgColi[18] += deltaColi / total[18];

}

$1 ~ /^3$/ && $2 ~ /^5000$/{
	versao[19] = $1
	n[19] = $2
	total[19]++;
	deltaColi = $3 - avgColi[19];
	avgColi[19] += deltaColi / total[19];
}

$1 ~ /^3$/ && $2 ~ /^10000$/{
	versao[20] = $1
	n[20] = $2
	total[20]++;
	deltaColi = $3 - avgColi[20];
	avgColi[20] += deltaColi / total[20];
}

$1 ~ /^3$/ && $2 ~ /^50000$/{
	versao[21] = $1
	n[21] = $2
	total[21]++;
	deltaColi = $3  - avgColi[21];
	avgColi[21] += deltaColi / total[21];
}

$1 ~ /^3$/ && $2 ~ /^100000$/{
	versao[22] = $1
	n[22] = $2
	total[22]++;
	deltaColi = $3  - avgColi[22];
	avgColi[22] += deltaColi / total[22];

}

$1 ~ /^3$/ && $2 ~ /^500000$/{
	versao[23] = $1
	n[23] = $2
	total[23]++;
	deltaColi = $3  - avgColi[23];
	avgColi[23] += deltaColi / total[23];

}

$1 ~ /^4$/ && $2 ~ /^1000$/{
	versao[24] = $1
	n[24] = $2
	total[24]++;
	deltaColi = $3 - avgColi[24];
	avgColi[24] += deltaColi / total[24];

}

$1 ~ /^4$/ && $2 ~ /^5000$/{
	versao[25] = $1
	n[25] = $2
	total[25]++;
	deltaColi = $3 - avgColi[25];
	avgColi[25] += deltaColi / total[25];
}

$1 ~ /^4$/ && $2 ~ /^10000$/{
	versao[26] = $1
	n[26] = $2
	total[26]++;
	deltaColi = $3 - avgColi[26];
	avgColi[26] += deltaColi / total[26];
}

$1 ~ /^4$/ && $2 ~ /^50000$/{
	versao[27] = $1
	n[27] = $2
	total[27]++;
	deltaColi = $3  - avgColi[27];
	avgColi[27] += deltaColi / total[27];
}

$1 ~ /^4$/ && $2 ~ /^100000$/{
	versao[28] = $1
	n[28] = $2
	total[28]++;
	deltaColi = $3  - avgColi[28];
	avgColi[28] += deltaColi / total[28];

}

$1 ~ /^4$/ && $2 ~ /^500000$/{
	versao[29] = $1
	n[29] = $2
	total[29]++;
	deltaColi = $3  - avgColi[29];
	avgColi[29] += deltaColi / total[29];

}

END{

	for(i = 0; i < 30; i++){

		printf("%d,%d,%.1f\n", versao[i], n[i], avgColi[i]) >> "tratadosCenario4.csv";
	}
}
