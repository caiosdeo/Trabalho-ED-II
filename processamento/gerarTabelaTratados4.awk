BEGIN{

  print "\\begin{table}[htbp]" >> "tabelaTratados4.tex";
  print "\\caption{Média das Métricas de Desempenho}" >> "tabelaTratados4.tex";
  print "\\label{tab:table4}" >> "tabelaTratados4.tex";
  print "\\begin{tabular}{c|c|c|c|c}" >> "tabelaTratados4.tex";
  print "\\textbf{Versão} & \\textbf{N} & \\textbf{Colisões}\\\\" >> "tabelaTratados4.tex";
  print "\\hline" >> "tabelaTratados4.tex";

}

{
    print $1, "&", $2, "&", $3, "\\\\">> "tabelaTratados4.tex";
}

END{

  print "\\end{tabular}" >> "tabelaTratados4.tex";
  print "\\end{table}" >> "tabelaTratados4.tex";
  
}
