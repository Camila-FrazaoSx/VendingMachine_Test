//CAMILA ALVES FRAZÃO 
//RA: 2840482121008
//GABRIEL LIMA DE ALMEIDA SILVA 
//RA:2840482121007 
//A SENHA DO MODO ADM ---> 5 (IMPORTANTE!!!)


#include <iostream>
using namespace std;

int code,Prod_Quant[8] = {5,5,5,5,5,5,5,5},mode;

  float Prod_Price[8] = {5.8, 5, 3.5, 8.1, 3, 7.5, 2.5, 4}, senha,lucro_atual = 0, lucro_futuro = 0;

  string Ident_Prod[8] = {"Doritos 84g R$ 5,80 <Codigo 0>","Ruffles 76g R$ 5,00 <Codigo 1>","eQlibri panetini 40g R$ 3,50 <Codigo 2>","TAKITOS tortilla 300g R$ 8,10 <Codigo 3>","KitKat 41,5g R$ 3,00 <Codigo 4>","Bombom FERRERO ROCHER 37,5g R$ 7,50 <Codigo 5>","Água Cristal 1,5 litro R$ 2,50 <Codigo 6>","Coca Cola 350 ml R$ 4,00 <Codigo 7>"};

  char count,reinicia = 'S';

void compra_prod(){

  float dindin,troco;
  // Seleção do produto (Modo Usuário)

          cout << endl;
          cout << "Selecione um produto digitando o codigo: " << endl;
          cin >> code;
          if (Prod_Quant[code]>0){
            // Mostrar na tela o produto escolhido e requisitando o dinheiro

            cout << "Voce selecionou " << Ident_Prod[code] << endl << " Insira o dinheiro" << endl;
            cin >> dindin;

            // Pagamento do produto

            while (dindin < Prod_Price[code]){

              cout << "Dinheiro insuficiente, insira valor correspondente ou maior que o do produto" << endl;
              cin >> dindin;

            }

            cout << "Voce inseriu R$" << dindin << endl;

            Prod_Quant[code]--; 

            cout << " O preco deste produto eh: R$ "<< Prod_Price[code] << endl;

            troco = dindin - Prod_Price[code];
            lucro_atual += Prod_Price[code];

            if (troco >= 0){

              cout << " O valor do seu troco eh: R$ " << troco << endl;

          }
        }
        else{
          cout << "produto indisponivel" << endl;
        } 
}

void repor_prod(){
  char dev = 'S';
  int quant;

      // Reposição dos produtos    

      while(dev == 'S' || dev == 's'){

        cout << "Indique o codigo do produto que deseja repor" << endl;
        cin >> code;

        cout << "Digite a quantidade de unidades para adicionar" << endl;
        cin >> quant;

        Prod_Quant[code] += quant;

        cout << "O produto de <Codigo " << code << "> possui atualmente " << Prod_Quant[code] << " unidades" << endl;;

        cout << "Se deseja adicionar mais unidades a outros produtos tecle (S)im ou (N)ao" << endl;
        cin >> dev;

      }
}

void lucro_at_ft(){
  cout <<" O lucro atual e de R$ "<< lucro_atual;

  for(int k = 0; k < 8; k++){

    lucro_futuro += Prod_Price[k] * Prod_Quant[k]; 

  }
  cout << "O lucro futuro e de R$ " << lucro_futuro << endl;
}

int main(){


  // Escolha do modo Usuário ou Administrador
  while(reinicia == 'S' || reinicia == 's'){

    cout << " Digite um modo < 1 para Cliente > < 2 para Administrador >" << endl;
    cin >> mode; 

    if(mode==1){

      cout << "Deseja adquirir um produto desta maravilhosa maquina?" << endl;
      cout << "(S)im ou (N)ao" << endl;
      cin >> count;

      while (count == 'S'|| count == 's'){

        for(int i=0;i < 8; i++){
          cout << "- " << Ident_Prod[i] << endl;
          cout << endl;
        }

          compra_prod();

          cout << "Deseja comprar outro produto (S)im ou (N)ao?" << endl;
          cin >> count;

        }
      }

    // Login do Modo Administrador

    else if (mode == 2){

      int resp;

      count = 'S';

      while(count == 'S'|| count == 's'){
        cout << "Digite a senha para entrar no modo ADM" << endl;
        cin >> senha;
        cout << endl;

        // Listagem da quantidade de produtos restantes na maquina 
        string Ident_ProdRestante[8] = {"-Doritos 84g <Codigo 0>","-Ruffles 76g <Codigo 1>","-eQlibri panetini 40g <Codigo 2>","-TAKITOS tortilla 300g <Codigo 3>","-KitKat 41,5g <Codigo 4>","-Bombom FERRERO ROCHER 37,5g <Codigo 5>","-Água Cristal 1,5 litro <Codigo 6>","-Coca Cola 350 ml <Codigo 7>"};

        if(senha == 5){
          cout << "Seja bem vindo ADM! Essa é a quantidade de produtos em sua maquina:" << endl << endl;

          for (int j = 0; j < 8; j++){

            cout << Ident_ProdRestante[j] << " possui " <<  Prod_Quant[j] << " unidades restantes " << endl;
            cout << endl;
          }

          cout << "Para repor produtos tecle 1, para calcular lucro atual e futuro tecle 2" << endl;
          cin >> resp;

          // Repor produtos da maquina
          if (resp == 1){

            repor_prod();

          }

          // Calculo do lucro atual e futuro da maquina

          else if(resp == 2 ){

            lucro_at_ft();

          } 
        }

        // Senha incorreta do Modo ADM 
        else {

          cout << "Senha incorreta! Deseja tentar novamente?" << endl;

          cout << "(S)im ou (N)ao" << endl;
          cin >> count;

        }

        cout << "Deseja fazer uma nova operacao?" << endl; 

        cout << "(S)im ou (N)ao" << endl;
        cin >> count;

      }
    }

    // Reiniciar a maquina
    else {
      cout << " Modo invalido!" << endl;
      }
    cout << " Deseja reiniciar a máquina e escolher outro modo? (S)im ou (N)ao" << endl;
    cin >> reinicia; 
  }

  return 0;
}
