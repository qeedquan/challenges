/*

Bands and Bonds is a browser clicker game about delving in a dungeon. It has the particularity that only one of the actions you may take can be auto-repeated at the same time: You may start several actions and have them count down in parallel, but only the last one you clicked will begin again after its end.

I thus started writing my own quick and dirty JS in the browser console:

setInterval(
    ()=>{
        for(btn of document.getElementsByClassName("can-hold")){
            btn.click()
    }
},50)
But quickly ran into several problems:

I want to avoid clicking abilties that have a cost, as that would drain my resources.
There are certain abilities that are straight up counter-productive, for example, one of them heals the enemy for no benefit.
Your task: Write a script, that when executed, starts autoclicking every wanted ability, but does not click unwanted ones, at least every 50 milliseconds.

Some rules:

All abilities have the css class .can-hold.
Abilities with a cost are unwanted. They all have a child that has the class .cost
Other unwanted abilities unfortunately do not have a nice and easy class. They all have a child that has text that contains one of ["restore", "Slows"], case sensitive. For the purposes of this challenge, assume these string are minimal.
What a script or program is is relaxed for this challenge. Pasting your submission in the browser console, using a bookmarklet, or even controlling the mouse through OS APIs (note that abilities may scroll off-screen!) are all allowed, as long as each ability ends up clicked at least every 50 ms.
It is allowed to manipulate the game's engine to consider all buttons clicked at all times, but you must demonstrate that this works according to the specs of the challenge.
This is mainly a javascript challenge, but all languages are welcome if they can achieve the task.
Here's the ungolfed snippet I finished the game with, you can consider it a reference implementation:

setInterval(()=>{
    for(entry of document.querySelectorAll(".can-hold:not(:has(.cost))")){
        if(!["Slows", "restore"].some((phrase)=>entry.textContent.includes(phrase))){
            entry.click()
        }
    }
 },50)

This is code-golf.

*/

setInterval(() => {
	for (entry of document.querySelectorAll(".can-hold:not(:has(.cost))")) {
		if (!["Slows", "restore"].some((phrase) => entry.textContent.includes(phrase))) {
			entry.click()
		}
	}
}, 50)

