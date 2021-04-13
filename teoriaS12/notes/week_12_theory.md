---
title: Week 12 - Engineering Ethics & Closing Comments
created: '2021-03-28T13:00:41.727Z'
modified: '2021-04-13T19:40:43.284Z'
---

# Week 12 - Engineering Ethics & Closing Comments

* Review of core concepts
* Engineering Ethics
* Continuous Improvement
* Look back at the beginning

# Review of Core Concepts

* Sprint 1:
  * Embedded Systems Fundamentals
  * SW Engineering: Requirements and Modeling
  * SW tools
* Sprint 2:
  * Agile Project Management
  * Software Architecture
  * Testing Techniques
* Sprint 3:
  * Building Software:
    * Optimization
    * Project work

Consider why have we done all this?

# Engineering Ethics

The last question leads on to remembering what is actually software engineering (should we call it Embedded Engineering?), and why is it important to be attained to certain professional principles, as other professionals.

## Why does it matter
We have a role in society. Just like doctors take the *Hippocratic Oath* in order to respect and protect fellow humans; engineers have the same duty of attaining themselves to the service of fellow humans.


## Therac-25
The following is a quote, translated into Spanish from *Set Phasers on Stun*, that describes the story of the Therac-25 Radiation Therapy machine:

> Voyne Ray Cox, 33, solo *Ray* para su familia y múltiples amigos, hizo una pequeña mueca cuando la piel expuesta de su estómago y pecho presionaba sobre la camilla helada posicionada bajo la gigante Therac-25.
>
> ... Era la novena sesión de radiación de Ray, desde la cirugía que tuvo para remover un tumor en su hombro izquierdo, y él esperaba que esta sesión fuese tan aburrida como las ocho anteriores...
>
> ... Ray, acostado boca-abajo con el canto de su cara descansando sobre la camilla, escuchaba las instrucciones ya familiaries de mantenerse quieto. El veía a Mary Beth (la ténico de radio-terapia) mientras ella operaba el control manual de la cónsola que rotaba la camilla y a él para posicionarlo en la posición correcta bajo el portal de la máquina.
>
> ... Para Ray, la máquina de radio-terapia era una maquinaria grande de aspecto atractivo, empaquetada en láminas de metal limpias y de textura suave. Pero, como le había sido explicado por los doctores y técnicos en el centro médico, la máquina de millones de dólares Therac-25 era el estado del arte en equipos de tratamiento de cáncer. Bajo la pulcra piel metálica estaba una compleja máquina, de aspecto amenazador, capaz de entregar un rayo de radiación de alta energía en cualquier parte del cuerpo de una persona. Había dos claves para el tratamiento exitoso del cáncer: acertárle a las células de cáncer de forma muy precisa, y poder tener varios tratamientos separados de bajas dósis, en vez de uno solo de dósis alta...
>
>... En ése momento, Mary Beth estaba en la cabina de control, así que el recostó su cabeza despues de decidir que lo mejor era ocuparse de sus propios asuntos y aprovechar la oportunidad de relajarse y estar quieto.
>
>... Dentro del pequeño cuarto de control, Mary Beth empezó a introducir comandos en el teclado de la computadora para iniciar el tratamiento. Ella estaba trabajando con un terminal muy común, un VT100 de la *Digital Equipment Corporation*, que estaba conectado a una computadora PDP-11 que controlaba el acelerador de radio-terapia. El sistema de control apuntaría el acelerador con gran precisión, y luego al estar listo, dispararía brevemente un haz de radiación de la intensidad prescrita. Ray Cox no debería sentir absolutamente nada.
>
>... La Therac-25 tenía dos modos de operación... Un modo era un haz de rayos X de alta intensidad, utilizando la capacidad completa de la máquina, de 25 Millones de EV. Este estado se seleccionaba presionando la tecla *"x"* en el teclado. Esto colocaba la máquina en potencia máxima e insertaba de forma automática una placa gruesa de metal justo debajo del haz de radiación.
>
>... El otro modo de operación era un modo de relativamente baja potencia, de haz de "electrones", y era seleccionado presionando la tecla *"e"*. Ray Cox estaba programado a ser tratado con este modo.
>
>... Mary Beth presionó la tecla *"x"* mientras se movía a la próxima entrada del teclado, para darse cuenta rápidamente que había presionado la letra incorrecta.
>
>... Con el error corregido, ella presionó rápidamente la tecla enter en el teclado, para así mover el cursor al fondo de la pantalla, para esperar por el mensage "Haz Preparado", que indicaría que la máquina estaba preparada para disparar el haz estrecho de radiación sobre la espalda de Ray Cox. Todo esto sucedió en el lapso de 8 segundos.
>
>... Ella no tenía idea que nadie había tecleado esta inusual, pero no inesperada, secuencia de comandos en las miles de veces esta Therac-25 en particular había sido operada.
>
>... La pantalla de su computadora mostraba que la máquina estaba en el modo requerido de "haz de electrones", pero de hecho se encontraba en un modo corrupto, en limbo, lista para entregar un chorro de 25000 rads a la espalda de Ray Cox, en un haz de protones alimentado por 25 millones de EV.
>
>... Ray Cox vio un destello de luz azul, escuchó un sonito como de fritura, y sintió el rayo invisible de radiación de alta energía saliendo de la Therac-25 cayendo sobre su espalda. Era como si una estaca de metal estuviese al rojo vivo atravesándole el pecho. Se sobresaltó en reflejo. El dolor intensísimo, nada remotamente parecido a los otros tratamientos.
>
>... Dentro de la cabina de control, aislada del exterior, la pantalla de Mary Beth mostraba el mensaje "Malfuncionamiento 54", indicando que algo no estaba funcionando y que el tratamiento no había sido iniciado. Sin tener ningún indicio de que la máquina había disparado, ella rápidamente re-inició la Therac-25 para que pudiese intentarlo de nuevo...
>
>... La luz azul destelló de nuevo, hubo un sonido como de algo muy caliente, y Ray, ahora condicionado y advertido, empezó a gritar para que se detuviese. Pero antes de que él pudiese terminar su grito aterrado, el haz de protones fue disparado desde arriba, llegándole esta vez a su cuello.
>
>... Afuera en la camilla de tratamiento, Ray Cox fue alcanzado por otro rayo mortal e invisible, en sus hombros y cuello, por tercera vez.
>
>... Ella respondió diciendo que raro era eso, que nada como eso había ocurrido jamás. Ella no tenía idea de que pudo haber ocurrido, pero no había nada de qué preocuparse, ya que la máquina había tenido un error y se había apagado de forma automática. De acuerdo a la pantalla Ray sólo había recibido un décimo de la dósis prescrita en su tratamiento.
>
>... Con la segunda ocurrencia (del incidente) fue aparente para Fritz Hager que había serios problemas con el sistema de control de la máquina.
>
>... El rayo azul que Ray vió antes de cada emisión provenía de la llamada radiación de Cherenkov, un fenómeno raro sólo visto cuando un haz de electrones es acelerado a velocidades extremas.
>
> *Meses más tarde...*
>
>... Alrededor de ese mismo tiempo, los doctores de Ray Cox empezaron a sospechar que había sido expuesto a una sobredosis masiva de radiación. Él había empezado a escupir sangre, y terribles quemaduras de radiación empezaron a aparecer en su espalda, hombro y cuello. Durante los próximos meses los tejidos tocados por los haces murieron y se desprendieron, dejando lesiones masivas con secciones faltantes de piel en su torso y espalda. Antes de su muerte cuatro meses después, Ray Cox mantuvo su buen carácter y humor, muchas veces bromeando en su acento de Texas que "El Capitán Kirk olvidó setear la máquina en atontar". (Captain Kirk forgot to put the machine on stun).


### Technical Considerations
Does this sound familiar:
* Something weird happens every now an then, it only takes a reset and it is fine.

>Leveson notes that a lesson to be drawn from the incident is to not assume that reused software is safe:[6] "A naive assumption is often made that reusing software or using commercial off-the-shelf software will increase safety because the software will have been exercised extensively. 

Reusing software modules does not guarantee safety in the new system to which they are transferred..."

This applies to re-using software/designs from previous projects into new ones.

### Software Engineering Code of Ethics
Code of Ethics from the IEEE-CS/ACM Joint Task Force on Software Engineering Ethics and Professional Practices:

1. PUBLIC – Software engineers shall act consistently with the public interest.

2. CLIENT AND EMPLOYER – Software engineers shall act in a manner that is in the best interests of their client and employer consistent with the public interest.

3. PRODUCT – Software engineers shall ensure that their products and related modifications meet the highest professional standards possible.

4. JUDGMENT – Software engineers shall maintain integrity and independence in their professional judgment.

5. MANAGEMENT – Software engineering managers and leaders shall subscribe to and promote an ethical approach to the management of software development and maintenance.

6. PROFESSION – Software engineers shall advance the integrity and reputation of the profession consistent with the public interest.

7. COLLEAGUES – Software engineers shall be fair to and supportive of their colleagues.

8. SELF – Software engineers shall participate in lifelong learning regarding the practice of their profession and shall promote an ethical approach to the practice of the profession.


# Continuous Improvement
Continuous Improvement is the act of becoming better, more effective, at the engineering practice. Pressman in Chapter 30 describes this for Software.


# Closing Comments
* Nissenbaum (1994) argues that responsibility in our computerized society is systematically undermined, and this is a disservice to the community. 
* Never stop learning, be always better.
* Hopefully we have shown you what you don't know, so you can use this as a guide, your own curricula, to continue your learning.



# References
* Pressman, Chapter 30, 32.
* [Set Phasers on Stun](https://archive.org/details/setphasersonstuntextbook)
* [Ethics Un-wrapped](https://ethicsunwrapped.utexas.edu/case-study/therac-25)
* [IEEE-CS/ACM Joint Task Force on Software Engineering Ethics and Professional Practices](https://www.computer.org/education/code-of-ethics)
 
