function playSound(character) {
    var audio = new Audio('voice/' + character + '.mp3');
    audio.play();
}