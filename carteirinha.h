#ifndef CARTEIRINHA_H_INCLUDED
#define CARTEIRINHA_H_INCLUDED

void carteirinha()
{
     string arquivoRenda = "dados_renda.txt";
     string arquivoDespesa = "dados_financeiros.txt";
     string arquivoCofre = "dados_cofre.txt";

     string mesAtual = obterMesAtual();
     double rendaTotal = somarRenda(arquivoRenda, mesAtual);
     double despesaTotal = extrairDespesas(arquivoDespesa, mesAtual);
     double totalGuardado = extrairCofrinho(arquivoCofre, mesAtual);

     string mesExtenso = converterMes(mesAtual);

     cout << "========== MINHA CARTEIRINHA DO MES " << mesExtenso << " ==========" << endl
          << endl;
     cout << "Estes dados servem para fornecer uma visão clara de sua situação financeira." << endl;
     cout << "Eles são fundamentais e podem te ajudar na tomada de decisões financeiras." << endl
          << endl;

     cout << "========== DETALHES DA RENDA ==========" << endl;
     importarRenda(arquivoRenda, mesAtual);
     cout << "" << endl;
     cout << "========== DETALHES DAS DESPESAS ==========" << endl;
     extrairDespesas(arquivoDespesa, mesAtual);
     cout << "" << endl;
     cout << "========== DETALHES DOS COFRINHOS ==========" << endl;
     extrairCofrinho(arquivoCofre, mesAtual);
     cout << "" << endl;
     cout << "========== RESUMO DO MES" << mesExtenso << " ==========" << endl;
     cout << "Total de Renda: $" << rendaTotal << endl;
     cout << "Total de Despesas: $" << despesaTotal << endl;
     cout << "Dinheiro Guardado: $" << totalGuardado << endl
          << endl;
     cout << "===================================================================" << endl
          << endl;
     cout << "Abaixo você encontrará um menu para edição dos dados do mes atual" << endl
          << endl;
}

#endif