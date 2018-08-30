#include <iostream>
using namespace std;
 
struct no {
    int valor;
    int magistrado;
    no *prox;
}typedef no;
 
void list_insert(no *ref, int valor, int magistrado) {
    no* novo;
    no* aux;
 
    novo = new no;
    novo->valor = valor;
    novo->magistrado = magistrado;
    novo->prox = NULL;
    aux = ref;
 
    if(aux->prox == NULL) {
        aux->prox = novo;
    } else {
        while (aux->prox != NULL)
            aux = aux->prox;
 
        aux->prox = novo;    
    }
 
}
 
no* list_pos(no *head, int pos) {
    no *n = head;
    int k = 0;
    while((k<pos)&&(n->prox!=NULL)) {
        k = k + 1;
        n = n->prox;
    }
    return n;
}
 
void stack_push(no *head, int valor, int magistrado) {
    no* novo;
 
    novo = new no;
    novo->valor = valor;
    novo->magistrado = magistrado;
    novo->prox = NULL;
    if(head->prox == NULL) {
        head->prox = novo;    
    } else {
    novo->prox = head->prox;
    head->prox = novo;
    }
}
 
no* list_remove(no *remove) {
    no* p = remove->prox;
    remove->prox = p->prox;
    delete p;
}
 
no* stack_pop(no* top) {
    list_remove(top);
}
 
int main() {
    int num_empresas, num_processos, id_magis, tempo, qtd_procs;
    cin >> num_empresas;
    no *emp[num_empresas];
    qtd_procs = 0;
 
 
    for(int i = 0;i<num_empresas;i++) {
        emp[i] = new no();
        cin >> num_processos;
        qtd_procs = qtd_procs + num_processos;
        for(int j = 0;j<num_processos;j++) {
            cin >> id_magis;
            cin >> tempo;
            list_insert(emp[i], tempo, id_magis);
        }
    }
    int num_magistrados;
    cin >> num_magistrados;
    int magistrados[num_magistrados];
    no *processo_magis[num_magistrados];
 
 
    for(int i = 0;i<num_magistrados;i++) {
        cin >> id_magis;
        magistrados[i] = id_magis;
        processo_magis[i] = new no();
    }
    int acompanhador = 0;
    int k = 0;
 
    while(k != qtd_procs) {
        for(int i = 0;i<num_empresas;i++) {
            if(acompanhador >= num_magistrados) {
                acompanhador = 0;
            }
            if(emp[i]->prox != NULL) {
                stack_push(processo_magis[acompanhador], list_pos(emp[i], 1)->valor, list_pos(emp[i], 1)->magistrado);
                k = k+1;
                list_remove(emp[i]);
                acompanhador = acompanhador + 1;
            }
        }
    }
 
 
    no *pilhas[2];
    pilhas[0] = new no(); // Seria o SY
    pilhas[1] = new no(); // Seria o S0
   
    for(int i = 0;i<num_magistrados;i++) {
        pilhas[1] = new no();
        for(int j = 0;j<num_magistrados;j++) {
            pilhas[0] = new no();
            if(i!=j) {
                while(processo_magis[i]->prox != NULL) {
                   // cout << "analisado:" << list_pos(processo_magis[i], 1)->valor << "\n";
                    if(processo_magis[i]->prox->magistrado == j+1) {
                        stack_push(pilhas[0], list_pos(processo_magis[i], 1)->valor, list_pos(processo_magis[i], 1)->magistrado);
                        stack_pop(processo_magis[i]);
                    } else {
                        stack_push(pilhas[1], list_pos(processo_magis[i], 1)->valor, list_pos(processo_magis[i], 1)->magistrado);
                        stack_pop(processo_magis[i]);
                        //cout << "fez isso";
                    }
                }
            }
                while(pilhas[0]->prox != NULL && (i!=j)) {
                    stack_push(processo_magis[j], list_pos(pilhas[0], 1)->valor, list_pos(pilhas[0], 1)->magistrado);
                    stack_pop(pilhas[0]);
                }

                while(pilhas[1]->prox != NULL && (i!=j)) {
                    stack_push(processo_magis[i], list_pos(pilhas[1], 1)->valor, list_pos(pilhas[1], 1)->magistrado);
                    stack_pop(pilhas[1]);
        }
        
        }// ERRO
        //processo_magis[i] = pilhas[1];
        /*cout << "pos1:" << list_pos(processo_magis[i], 1)->valor << "\n";
        cout << "pos2:" << list_pos(processo_magis[i], 2)->valor << "\n";
        cout << "pos3:" << list_pos(processo_magis[i], 3)->valor << "\n";*/
    }
 

    // agora, temos os magistrados com os seus devidos processos em suas mesas.
}