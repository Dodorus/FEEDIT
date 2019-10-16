# FEEDIT

Also Ablauf:

1. Aufwachen
2. WLAN-Modul starten
3. Im bestehenden WLAN einloggen
4. Calibrierungswert einstellen: calValue = 400.0; // Calib Wert
5. Wenn sich Loadcell (Sensor) von jeglichen Schwingungen erholt hat, einen Wert in Gramm oder KG ausgeben: float i = LoadCell.getData();

@Michael *Problem ist hier, dass immer der Wert 0.00 ausgelesen wird. Als würde die Loadcell nicht aus dem Tiefschlaf erwachen. Blödi biatsch*

6. Wieder einschlafen