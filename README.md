# FlyBox2_encoder_module

This is the code for an additional module for the [FlyBox2 project](https://github.com/mancio/FlyBox2)
Is design using an Arduino Pro Micro and is required to add up to two encoders to the main project due 
to the fact that the Pro Micro has only 5 interrupt and for 3 encoders we need 6 interrupts.
If we use not-interrupts pin the encoder become impossible to control (it show left and right movements at
the same time)