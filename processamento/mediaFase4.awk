#Script para extrair os dados brutos da saída do programa

BEGIN{

	estrutura[8];
	n[8];

	deltaComp; # delta compressao
	deltaArm; # delta armazenamento
	deltaTempo;
	
	avgComp[8];
	avgArm[8];
	avgTempo[8];

	total[8];
	
	for(i = 0; i < 8; i++){

		avgComp[i] = 0;
		avgArm[i] = 0;
		avgTempo[i] = 0;
		total[i] = 0;
	
	}

}

# $1         $2     $3          $4              $5   
# estrutura, n, taxaCompressao, armazenamento, tempo

# 0 - Huffman;
$1 ~ /^0$/ && $2 ~ /^1000$/{

	indice = 0;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

$1 ~ /^0$/ && $2 ~ /^5000$/{

	indice = 1;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

$1 ~ /^0$/ && $2~ /^10000$/{

	indice = 2;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

$1 ~ /^0$/ && $2 ~ /^17000$/{

	indice = 3;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

# 1 - LZW
$1 ~ /^1$/ && $2 ~ /^1000$/{

	indice = 4;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

$1 ~ /^1$/ && $2 ~ /^5000$/{

	indice = 5;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

$1 ~ /^1$/ && $2 ~ /^10000$/{

	indice = 6;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

$1 ~ /^1$/ && $2 ~ /^17000$/{

	indice = 7;

    estrutura[indice] = $1
    n[indice] = $2
    total[indice]++;
    deltaComp = $3 - avgComp[indice];
    avgComp[indice] += deltaComp / total[indice];
    deltaArm = $4 - avgArm[indice];
    avgArm[indice] += deltaArm / total[indice];
    deltaTempo = $5 - avgTempo[indice];
    avgTempo[indice] += deltaTempo / total[indice];

}

END{

	for(i = 0; i < 8; i++){

		printf("%d,%d,%.1f,%.1f,%.1f\n", estrutura[i], n[i], avgComp[i], avgArm[i], avgTempo[i]) >> "mediasFase4.csv";
	}
}
