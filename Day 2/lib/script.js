//Import three.js
import * as THREE from "https://cdn.skypack.dev/three@0.129.0/build/three.module.js";

//allow for the camera to move 
import { OrbitControls } from "https://cdn.skypack.dev/three@0.129.0/examples/jsm/controls/OrbitControls.js";
//importing .gltf file
import { GLTFLoader } from "https://cdn.skypack.dev/three@0.129.0/examples/jsm/loaders/GLTFLoader.js";

const scene = new THREE.Scene(); //makes the overall scene, you will always need this

const camera = new THREE.PerspectiveCamera(80, window.innerWidth / window.innerHeight, .1, 1000);


//keep the object and camera as global
let object;

let controls;


//set the object to load
let objToRender = "room";

const loader = new GLTFLoader();

loader.load('assets/room.gltf', function (gltf) {
    object = gltf.scene;
    scene.add(object);
}
);

const renderer = new THREE.WebGLRenderer({ alpha: true });
renderer.setSize(window.innerWidth, window.innerHeight);

document.getElementById("container3D").appendChild(renderer.domElement);

const topLight = new THREE.DirectionalLight(0xffffff, 1);
topLight.position.set(500, 500, 500);
topLight.castShadow = true;
scene.add(topLight);

const ambientLight = new THREE.ambientLight(0x333333);

scene.add(ambientLight);

function animate() {
    requestAnimationFrame(animate);
}

window.addEventListener("resize", function () {
    camera.aspect = window.innerWidth / this.window.innerHeight;
    camera.updateProjectionmatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
});

animate();
