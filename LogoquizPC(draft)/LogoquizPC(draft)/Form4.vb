Public Class Form4
    Public Shared quiz As Integer
    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Close()
        Form2.Show()
    End Sub

    Public Sub Form4_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        Label2.Text = Form2.Level
        If My.Settings.correction(Form2.LevelIdent + 0) = 1 Then
            PictureBox31.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 1) = 1 Then
            PictureBox32.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 2) = 1 Then
            PictureBox33.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 3) = 1 Then
            PictureBox34.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 4) = 1 Then
            PictureBox35.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 5) = 1 Then
            PictureBox36.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 6) = 1 Then
            PictureBox37.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 7) = 1 Then
            PictureBox38.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 8) = 1 Then
            PictureBox39.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 9) = 1 Then
            PictureBox40.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 10) = 1 Then
            PictureBox41.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 11) = 1 Then
            PictureBox42.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 12) = 1 Then
            PictureBox43.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 13) = 1 Then
            PictureBox44.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 14) = 1 Then
            PictureBox45.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 15) = 1 Then
            PictureBox46.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 16) = 1 Then
            PictureBox47.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 17) = 1 Then
            PictureBox48.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 18) = 1 Then
            PictureBox49.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 19) = 1 Then
            PictureBox50.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 20) = 1 Then
            PictureBox51.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 21) = 1 Then
            PictureBox52.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 22) = 1 Then
            PictureBox53.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 23) = 1 Then
            PictureBox54.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 24) = 1 Then
            PictureBox55.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 25) = 1 Then
            PictureBox56.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 26) = 1 Then
            PictureBox57.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 27) = 1 Then
            PictureBox58.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 28) = 1 Then
            PictureBox59.Visible = True
        End If
        If My.Settings.correction(Form2.LevelIdent + 29) = 1 Then
            PictureBox60.Visible = True
        End If
    End Sub

    Private Sub PictureBox1_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox1.Click
        Form5.PictureBox1.Image = PictureBox1.Image
        quiz = 0
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox2_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox2.Click
        Form5.PictureBox1.Image = PictureBox2.Image
        quiz = 1
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub Picturebox3_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox3.Click
        Form5.PictureBox1.Image = PictureBox3.Image
        quiz = 2
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox4_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox4.Click
        Form5.PictureBox1.Image = PictureBox4.Image
        quiz = 3
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox5_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox5.Click
        Form5.PictureBox1.Image = PictureBox5.Image
        quiz = 4
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox6_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox6.Click
        Form5.PictureBox1.Image = PictureBox6.Image
        quiz = 5
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox7_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox7.Click
        Form5.PictureBox1.Image = PictureBox7.Image
        quiz = 6
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox8_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox8.Click
        Form5.PictureBox1.Image = PictureBox8.Image
        quiz = 7
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox9_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox9.Click
        Form5.PictureBox1.Image = PictureBox9.Image
        quiz = 8
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox10_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox10.Click
        Form5.PictureBox1.Image = PictureBox10.Image
        quiz = 9
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox11_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox11.Click
        Form5.PictureBox1.Image = PictureBox11.Image
        quiz = 10
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox12_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox12.Click
        Form5.PictureBox1.Image = PictureBox12.Image
        quiz = 11
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox13_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox13.Click
        Form5.PictureBox1.Image = PictureBox13.Image
        quiz = 12
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox14_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox14.Click
        Form5.PictureBox1.Image = PictureBox14.Image
        quiz = 13
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox15_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox15.Click
        Form5.PictureBox1.Image = PictureBox15.Image
        quiz = 14
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox16_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox16.Click
        Form5.PictureBox1.Image = PictureBox16.Image
        quiz = 15
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox17_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox17.Click
        Form5.PictureBox1.Image = PictureBox17.Image
        quiz = 16
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox18_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox18.Click
        Form5.PictureBox1.Image = PictureBox18.Image
        quiz = 17
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox19_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox19.Click
        Form5.PictureBox1.Image = PictureBox19.Image
        quiz = 18
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox20_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox20.Click
        Form5.PictureBox1.Image = PictureBox20.Image
        quiz = 19
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox21_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox21.Click
        Form5.PictureBox1.Image = PictureBox21.Image
        quiz = 20
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox22_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox22.Click
        Form5.PictureBox1.Image = PictureBox22.Image
        quiz = 21
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox23_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox23.Click
        Form5.PictureBox1.Image = PictureBox23.Image
        quiz = 22
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox24_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox24.Click
        Form5.PictureBox1.Image = PictureBox24.Image
        quiz = 23
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox25_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox25.Click
        Form5.PictureBox1.Image = PictureBox25.Image
        quiz = 24
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox26_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox26.Click
        Form5.PictureBox1.Image = PictureBox26.Image
        quiz = 25
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox27_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox27.Click
        Form5.PictureBox1.Image = PictureBox27.Image
        quiz = 26
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox28_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox28.Click
        Form5.PictureBox1.Image = PictureBox28.Image
        quiz = 27
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox29_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox29.Click
        Form5.PictureBox1.Image = PictureBox29.Image
        quiz = 28
        Me.Hide()
        Form5.Show()
    End Sub
    Private Sub PictureBox30_Click(sender As System.Object, e As System.EventArgs) Handles PictureBox30.Click
        Form5.PictureBox1.Image = PictureBox30.Image
        quiz = 29
        Me.Hide()
        Form5.Show()
    End Sub
End Class