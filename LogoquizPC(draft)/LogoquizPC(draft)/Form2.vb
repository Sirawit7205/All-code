Public Class Form2
    Public Shared LevelIdent As Integer
    Public Level As Integer
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Me.Close()
        Form1.Show()
    End Sub

    Private Sub Form2_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        TextBox1.Text = My.Settings.correct
        TextBox2.Text = My.Settings.score
        Label4.Text = 30 - My.Settings.lv1 & " quiz(es) left."
        If My.Settings.correct < 20 Then
            Label5.Text = 20 - My.Settings.correct & " more correct answers needed."
        Else
            Button3.Enabled = True
            Label5.Text = 30 - My.Settings.lv2 & " quiz(es) left."
        End If
        If My.Settings.correct < 40 Then
            Label6.Text = 40 - My.Settings.correct & " more correct answers needed."
        Else
            Button4.Enabled = True
            Label6.Text = 30 - My.Settings.lv3 & " quiz(es) left."
        End If
        If My.Settings.correct < 60 Then
            Label7.Text = 60 - My.Settings.correct & " more correct answers needed."
        Else
            Button5.Enabled = True
            Label7.Text = 30 - My.Settings.lv4 & " quiz(es) left."
        End If
        If My.Settings.correct < 80 Then
            Label8.Text = 80 - My.Settings.correct & " more correct answers needed."
        Else
            Button6.Enabled = True
            Label8.Text = 30 - My.Settings.lv5 & " quiz(es) left."
        End If
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        LevelIdent = 0
        Level = 1
        LevelLoader()
        Form4.Show()
        Close()
    End Sub
    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        LevelIdent = 30
        Level = 2
        LevelLoader()
        Form4.Show()
        Close()
    End Sub

    Private Sub Button4_Click(sender As System.Object, e As System.EventArgs) Handles Button4.Click
        LevelIdent = 60
        Level = 3
        LevelLoader()
        Form4.Show()
        Close()
    End Sub

    Private Sub Button5_Click(sender As System.Object, e As System.EventArgs) Handles Button5.Click
        LevelIdent = 90
        Level = 4
        LevelLoader()
        Form4.Show()
        Close()
    End Sub

    Private Sub Button6_Click(sender As System.Object, e As System.EventArgs) Handles Button6.Click
        LevelIdent = 120
        Level = 5
        LevelLoader()
        Form4.Show()
        Close()
    End Sub

    Public Sub LevelLoader()
        Form4.PictureBox1.Image = ImageList1.Images(LevelIdent + 0)
        Form4.PictureBox2.Image = ImageList1.Images(LevelIdent + 1)
        Form4.PictureBox3.Image = ImageList1.Images(LevelIdent + 2)
        Form4.PictureBox4.Image = ImageList1.Images(LevelIdent + 3)
        Form4.PictureBox5.Image = ImageList1.Images(LevelIdent + 4)
        Form4.PictureBox6.Image = ImageList1.Images(LevelIdent + 5)
        Form4.PictureBox7.Image = ImageList1.Images(LevelIdent + 6)
        Form4.PictureBox8.Image = ImageList1.Images(LevelIdent + 7)
        Form4.PictureBox9.Image = ImageList1.Images(LevelIdent + 8)
        Form4.PictureBox10.Image = ImageList1.Images(LevelIdent + 9)
        Form4.PictureBox11.Image = ImageList1.Images(LevelIdent + 10)
        Form4.PictureBox12.Image = ImageList1.Images(LevelIdent + 11)
        Form4.PictureBox13.Image = ImageList1.Images(LevelIdent + 12)
        Form4.PictureBox14.Image = ImageList1.Images(LevelIdent + 13)
        Form4.PictureBox15.Image = ImageList1.Images(LevelIdent + 14)
        Form4.PictureBox16.Image = ImageList1.Images(LevelIdent + 15)
        Form4.PictureBox17.Image = ImageList1.Images(LevelIdent + 16)
        Form4.PictureBox18.Image = ImageList1.Images(LevelIdent + 17)
        Form4.PictureBox19.Image = ImageList1.Images(LevelIdent + 18)
        Form4.PictureBox20.Image = ImageList1.Images(LevelIdent + 19)
        Form4.PictureBox21.Image = ImageList1.Images(LevelIdent + 20)
        Form4.PictureBox22.Image = ImageList1.Images(LevelIdent + 21)
        Form4.PictureBox23.Image = ImageList1.Images(LevelIdent + 22)
        Form4.PictureBox24.Image = ImageList1.Images(LevelIdent + 23)
        Form4.PictureBox25.Image = ImageList1.Images(LevelIdent + 24)
        Form4.PictureBox26.Image = ImageList1.Images(LevelIdent + 25)
        Form4.PictureBox27.Image = ImageList1.Images(LevelIdent + 26)
        Form4.PictureBox28.Image = ImageList1.Images(LevelIdent + 27)
        Form4.PictureBox29.Image = ImageList1.Images(LevelIdent + 28)
        Form4.PictureBox30.Image = ImageList1.Images(LevelIdent + 29)
    End Sub
End Class