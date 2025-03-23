# todo
cada dispositivo possui características próprias, mas compartilha
funcionalidades comuns com outros dispositivos.

modele diferentes dispositivos industriais
utilizando conceitos de:
* herança 
* métodos virtuais
* métodos virtuais puros
* classes abstratas

1. Classe Abstrata: `dispositivo_industrial`
classe abstrata que servirá como base para todos os tipos de dispositivos 
significado: uma classe abstrata é que utiliza apenas de métodos virtuais puros
1.2 dispositivo_industrial contém os seguintes atributos:
* `string id` // identificador único do dispositivo
* `bool status` // indica se o dispositivo está ligado ou desligado
* `double temperatura` // temperatura atual do dispositivo
1.3 `dispositivo_industrial` contém os seguintes métodos públicos:
* Getters e Setters para atributos
* Método virtual `verificar_seguranca()` // retorna um booleano indicando se 
o dispositivo está operando em condições seguras.
* Método virtual puro `iniciar()` // coloca o dispositivo em funcionamento
* Método virtual puro `gerar_relatorio()` // retorna uma string com informações 
sobre o estado atual do dispositivo
* Destrutor virtual 

2. Classes Concretas
2.1 `sensor_temperatura`



