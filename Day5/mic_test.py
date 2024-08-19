import speech_recognition as sr
def main():
    r = sr.Recognizer()

    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source)

        print("Say Something:")
        audio = r.listen(source) #listens to the source
        if str(r.recognize_google(audio)) == "dining":
            print("Grubhub API")
        elif str(r.recognize_google(audio)) == "i-g gather":
            print("AirBNB")
        else:
            print("No Option")
        while str(r.recognize_google(audio)) != "stop":
            audio = r.listen(source)
            try:
                a = str(r.recognize_google(audio)) #get string rep of the audio
                print(a + "\n")

            except Exception as e:
                
                print("Error : " + str(e))

if __name__ == "__main__":
    main()